#include "state_video_preview.h"
#include "ap_video_preview.h"
#include "ap_state_handling.h"
#include "ap_state_config.h"
#include "ap_video_record.h"
#include "ap_display.h"
#include "avi_encoder_app.h"

//+++
INT8U pic_flag;
INT32U photo_check_time_loop_count = 0;
INT32U photo_check_time_preview_count = 0;

#define CONTINUOUS_SHOOTING_COUNT_MAX	5

//	prototypes
void state_video_preview_init(void);
void state_video_preview_exit(void);


extern INT8U ap_state_config_usb_mode_get(void);

void state_photo_check_timer_isr(void)
{
    photo_check_time_loop_count++;

    /*
    	MSG_APQ_CONNECT_TO_PC / MSG_APQ_MENU_KEY_ACTIVE / MSG_APQ_MODE
    */
    if((pic_flag == 2) || (pic_flag == 3) || (pic_flag == 4))
    {
        photo_check_time_loop_count = photo_check_time_preview_count;
    }

    if(photo_check_time_loop_count >= photo_check_time_preview_count)
    {
        msgQSend(ApQ, MSG_APQ_CAPTURE_PREVIEW_ON, NULL, NULL, MSG_PRI_NORMAL);
        timer_stop(TIMER_C);
    }
}

void state_video_preview_init(void)
{
    DBG_PRINT("video_preview state init enter\r\n");
    ap_video_preview_init();
}
volatile INT8U pic_down_flag = 0;
//extern INT8U  File_creat_ok;
void state_video_preview_entry(void *para)
{
    EXIT_FLAG_ENUM exit_flag = EXIT_RESUME;
    INT32U msg_id, file_path_addr, led_type;
    INT32U *prev_state;
    STAudioConfirm *audio_temp;
    INT8U continuous_shooting_count = 0;
    INT8U photo_check_time_flag;
    INT32U photo_check_time_start;
    INT32U photo_check_time_end;
    INT32U photo_check_time_count_ms;
    INT32U photo_check_ui_setting_ms;
    INT32S nRet;
    pic_flag = 0;
    prev_state = para;


    if(ap_state_handling_storage_id_get() == NO_STORAGE)   //not to use burst when no SD card inserted
    {
        photo_check_time_flag = ap_state_config_preview_get();
    }
    else if(ap_state_config_burst_get())
    {
        photo_check_time_flag = 0;
    }
    else
    {
        photo_check_time_flag = ap_state_config_preview_get();
    }
	

#if (!ENABLE_SAVE_SENSOR_RAW_DATA)
    ap_video_capture_mode_switch(0, STATE_VIDEO_PREVIEW);
#endif
    if (*(INT32U *) para == STATE_VIDEO_RECORD)
    {
    	msgQSend(ApQ, MSG_APQ_CAPTUER_ACTIVE, NULL, NULL, MSG_PRI_NORMAL);
    }
    
    state_video_preview_init();
    DBG_PRINT("Video_preview_init!\r\n");

    while (exit_flag == EXIT_RESUME)
    {
        if (msgQReceive(ApQ, &msg_id, (void *) ApQ_para, AP_QUEUE_MSG_MAX_LEN) == STATUS_FAIL)
        {
            continue;
        }

        switch (msg_id)
        {
        case EVENT_APQ_ERR_MSG:
            audio_temp = (STAudioConfirm *)ApQ_para;
            if((audio_temp->result == AUDIO_ERR_DEC_FINISH) && (audio_temp->source_type == AUDIO_SRC_TYPE_APP_RS))
            {
                //gpio_write_io(SPEAKER_EN, DATA_LOW);
            }
            else
            {
                audio_confirm_handler((STAudioConfirm *)ApQ_para);
            }
            break;
        case MSG_STORAGE_SERVICE_MOUNT:
            ap_state_handling_storage_id_set(ApQ_para[0]);
            ap_state_handling_icon_clear_cmd(ICON_INTERNAL_MEMORY, NULL, NULL);
            ap_state_handling_icon_show_cmd(ICON_SD_CARD, NULL, NULL);
            ap_state_handling_str_draw_exit();
            left_capture_num = cal_left_capture_num();
            left_capture_num_display(left_capture_num);
            //	led_type = LED_WAITING_CAPTURE;
            //	msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
            DBG_PRINT("[Video Preview Mount OK]\r\n");
            break;
        case MSG_STORAGE_SERVICE_NO_STORAGE:
            led_type = LED_NO_SDC;
			__msg("led_type = %d\n", led_type);
            msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
            ap_state_handling_storage_id_set(ApQ_para[0]);
            ap_state_handling_icon_clear_cmd(ICON_SD_CARD, NULL, NULL);
            ap_state_handling_icon_show_cmd(ICON_INTERNAL_MEMORY, NULL, NULL);
            left_capture_num = cal_left_capture_num();
            left_capture_num_display(left_capture_num);
            DBG_PRINT("[Video Preview Mount FAIL]\r\n");
            break;
        case MSG_APQ_MD_SET:
            if(pic_flag == 0)
            {
                ap_peripheral_auto_off_force_disable_set(1);
                led_type = LED_MONTION_WAIT;
                msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
                ap_state_config_md_set(1);
                vid_enc_disable_sensor_clock();
                OSQPost(StateHandlingQ, (void *) STATE_VIDEO_RECORD);
                exit_flag = EXIT_BREAK;
            }
            //msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_MOTION_DETECT_START, NULL, NULL, MSG_PRI_NORMAL);
            //ap_video_record_sts_set(VIDEO_RECORD_MD);
            break;

        case MSG_APQ_MENU_KEY_ACTIVE:
            if(pic_flag == 0)
            {
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
                vid_enc_disable_sensor_clock();
                OSQPost(StateHandlingQ, (void *) STATE_SETTING);
                exit_flag = EXIT_BREAK;
            }
            else
            {
                pic_flag = 3;
            }
            break;

        case MSG_APQ_NEXT_KEY_ACTIVE:
        case MSG_APQ_PREV_KEY_ACTIVE:
            if(pic_flag == 0)
            {
                if(msg_id == MSG_APQ_NEXT_KEY_ACTIVE)
                {
                    ap_video_record_zoom_inout(0);
                }
                else
                {
                    ap_video_record_zoom_inout(1);
                }
            }
            break;
        case MSG_APQ_AUDO_ACTIVE:
            if(pic_flag == 0)
            {
                vid_enc_disable_sensor_clock();
                OSQPost(StateHandlingQ, (void *) STATE_AUDIO_RECORD);
                led_type = LED_WAITING_AUDIO_RECORD;
                msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
                exit_flag = EXIT_BREAK;
            }
            break;

        case MSG_APQ_VIDEO_RECORD_ACTIVE:
            //	break;
            //case MSG_APQ_MODE:
            __msg("MSG_APQ_VIDEO_RECORD_ACTIVE\n");
            if(pic_flag == 0)
            {
#if 0// GPDV_BOARD_VERSION != GPCV1237A_Aerial_Photo
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
                vid_enc_disable_sensor_clock();
                OSQPost(StateHandlingQ, (void *) STATE_BROWSE);
#else
                vid_enc_disable_sensor_clock();
                OSQPost(StateHandlingQ, (void *) STATE_VIDEO_RECORD);
#endif
                exit_flag = EXIT_BREAK;
            }
            else
            {
                pic_flag = 4;
            }
            break;

        case MSG_APQ_FUNCTION_KEY_ACTIVE:
#if KEY_FUNTION_TYPE == SAMPLE2
            //break;
#endif
        case MSG_APQ_CAPTUER_ACTIVE:
        case MSG_APQ_CAPTURE_KEY_ACTIVE:
        case MSG_APQ_CAPTURE_CONTINUOUS_SHOOTING:
			__msg("MSG_APQ_CAPTURE_KEY_ACTIVE\n");
            nRet = 0; //_devicemount(MINI_DVR_STORAGE_TYPE);
            if(nRet == 0)
            {
                pic_down_flag = 1;
                if(pic_flag == 0)
                {
                	/* add begin by Zhibo, 2017-05-03 */
					state_video_capute_moto_led_ctl();              	
                	/* add end by Zhibo, 2017-05-03 */
                    if(ap_video_preview_func_key_active() < 0)
                    {
						__msg("ap_video_preview_func_key_active () less < 0\n");
                        pic_flag = 0;
                        pic_down_flag = 0;
                        //  File_creat_ok=0;
                        ap_state_handling_file_creat_set(0);

                    }
                    else
                    {
						__msg("ap_video_preview_func_key_active () more < 0\n");
                        pic_flag = 1;
                        photo_check_time_start = OSTimeGet();
						/* add begin by Zhibo, 2017-05-03 */
						led_red_on();
						/* add end by Zhibo, 2017-05-03 */
                    }
                }
            }
            else
            {
                led_type = LED_NO_SDC;
				__msg("led_type = %d\n", led_type);
                msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
            }
            break;

        case MSG_STORAGE_SERVICE_PIC_REPLY:
            if(ap_video_preview_reply_action((STOR_SERV_FILEINFO *) ApQ_para) < 0)
            {
                pic_flag = 0;
                pic_down_flag = 0;
                //File_creat_ok=0;
                ap_state_handling_file_creat_set(0);
#if 0
                if(ap_state_handling_storage_id_get() != NO_STORAGE)
                {
                    led_type = LED_CAPTURE_FAIL;
                    msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
                    DBG_PRINT("--------cap_fail------\r\n");
                }
#endif
                break;
            }
            //fankun
            if(ap_state_handling_file_creat_get())
            {
                led_type = LED_CAPTURE;
                msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
                DBG_PRINT("--------Set_cap_mode------\r\n");
            }
            else
            {
                led_type = LED_NO_SDC;
				__msg("led_type = %d\n", led_type);
                msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
            }
            file_path_addr = ((STOR_SERV_FILEINFO *) ApQ_para)->file_path_addr;
            break;

        case MSG_STORAGE_SERVICE_PIC_DONE:
            ap_video_preview_reply_done(ApQ_para[0], file_path_addr);
            if(ap_state_handling_file_creat_get())
            {
                DBG_PRINT("-----set_cap_wait----\r\n");
                led_type = LED_WAITING_CAPTURE;
                msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
            }
            pic_down_flag = 0;
            //File_creat_ok=0;
            ap_state_handling_file_creat_set(0);

            if(photo_check_time_flag)
            {
                photo_check_time_end = OSTimeGet();
                photo_check_ui_setting_ms = ((photo_check_time_flag * 3) - 1) * 1000; // ms

                photo_check_time_count_ms = (photo_check_time_end - photo_check_time_start) * 10; //ms

                if(photo_check_time_count_ms < photo_check_ui_setting_ms)
                {
                    photo_check_time_loop_count = 0;
                    photo_check_time_preview_count = (photo_check_ui_setting_ms - photo_check_time_count_ms) / 100;
                    timer_msec_setup(TIMER_C, 100, 0, state_photo_check_timer_isr); // 100 ms
                    break;
                }
            }
        case MSG_APQ_CAPTURE_PREVIEW_ON:
            if(pic_flag == 2)   // Connect To PC
            {
#if GPDV_BOARD_VERSION != GPCV1237A_Aerial_Photo
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
#endif

                vid_enc_disable_sensor_clock();
                video_encode_preview_off();
                ap_state_handling_connect_to_pc(STATE_VIDEO_PREVIEW);
                break;
            }
            else if(pic_flag == 3)     // MEMU Key
            {
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
                OSQPost(StateHandlingQ, (void *) STATE_SETTING);
                exit_flag = EXIT_BREAK;
                break;
            }
            else if(pic_flag == 4)     // MODE Key
            {
#if GPDV_BOARD_VERSION != GPCV1237A_Aerial_Photo
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
                OSQPost(StateHandlingQ, (void *) STATE_BROWSE);
#else
                OSQPost(StateHandlingQ, (void *) STATE_VIDEO_RECORD);
#endif
                exit_flag = EXIT_BREAK;
                break;
            }
            else if(pic_flag == 5)     // HDMI insert
            {
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
                OSQPost(StateHandlingQ, (void *) STATE_BROWSE);
                msgQSend(ApQ, MSG_APQ_HDMI_PLUG_IN, NULL, NULL, MSG_PRI_NORMAL);
                exit_flag = EXIT_BREAK;
                break;
            }
            else if((pic_flag == 6) || (pic_flag == 7))     // TV plug in/out
            {
                vid_enc_disable_sensor_clock();

                if(pic_flag == 6)
                {
                    ap_state_handling_tv_init();
                }
                else
                {
                    ap_state_handling_tv_uninit();
                }

                ap_video_capture_mode_switch(0, STATE_VIDEO_PREVIEW);
                video_capture_resolution_display();
                left_capture_num = cal_left_capture_num();
                left_capture_num_display(left_capture_num);

                pic_flag = 0;
                break;
            }

            /* sensorぃ闽,盢sensor 癳戈ま旧┏糷preview flow */
#if ENABLE_SAVE_SENSOR_RAW_DATA
            ap_video_capture_mode_switch(0, STATE_VIDEO_RECORD);
#else
            ap_video_capture_mode_switch(0, STATE_VIDEO_PREVIEW);
#endif
            /*
            	╃酚家Α硈╃
            */
            if(ap_state_config_burst_get() && (ap_state_handling_storage_id_get() != NO_STORAGE))
            {
                continuous_shooting_count++;
                if(continuous_shooting_count < CONTINUOUS_SHOOTING_COUNT_MAX)
                {
                    msgQSend(ApQ, MSG_APQ_CAPTURE_CONTINUOUS_SHOOTING, NULL, NULL, MSG_PRI_NORMAL);
                }
                else
                {
                    continuous_shooting_count = 0;
                }
            }

            pic_flag = 0;

            break;

        case MSG_APQ_POWER_KEY_ACTIVE:
			__msg("MSG_APQ_POWER_KEY_ACTIVE\n");
            video_encode_exit();
            OSTimeDly(10);
            ap_state_handling_power_off();
            break;

#if C_BATTERY_DETECT == CUSTOM_ON
        case MSG_APQ_BATTERY_LVL_SHOW:
            ap_state_handling_battery_icon_show(ApQ_para[0]);
            break;
        case MSG_APQ_BATTERY_CHARGED_SHOW:
            ap_state_handling_charge_icon_show(1);
            break;
        case MSG_APQ_BATTERY_CHARGED_CLEAR:
            ap_state_handling_charge_icon_show(0);
            break;
        case MSG_APQ_BATTERY_LOW_SHOW:
            ap_state_handling_clear_all_icon();
            OSTimeDly(5);
            ap_state_handling_str_draw_exit();
            ap_state_handling_str_draw(STR_BATTERY_LOW, WARNING_STR_COLOR);
            msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_BATTERY_LOW_BLINK_START, NULL, NULL, MSG_PRI_NORMAL);
            break;
#endif

        case MSG_APQ_CONNECT_TO_PC:
            //	led_type = LED_USB_CONNECT;//LED_RECORD;
            //	msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
#if GPDV_BOARD_VERSION != GPCV1237A_Aerial_Photo
            if(ap_display_get_device() != DISP_DEV_TFT) break;
            msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TV_POLLING_STOP, NULL, NULL, MSG_PRI_NORMAL);
            OSTimeDly(3);
#endif
            if(pic_flag == 0)
            {
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
                vid_enc_disable_sensor_clock();
                video_encode_preview_off();
                ap_state_handling_connect_to_pc(STATE_VIDEO_PREVIEW);
            }
            else
            {
                pic_flag = 2;
            }
            break;

        case MSG_APQ_DISCONNECT_TO_PC:
            //led_type = LED_WAITING_CAPTURE;
            //msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_LED_SET, &led_type, sizeof(INT32U), MSG_PRI_NORMAL);
#if GPDV_BOARD_VERSION != GPCV1237A_Aerial_Photo
            msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TV_POLLING_START, NULL, NULL, MSG_PRI_NORMAL);
#endif
            ap_state_handling_disconnect_to_pc();
            OSTimeDly(50);
            /*
            	盢web campreview 旧,ち传Θcapture preview
            */
            pic_flag = 0;
            vid_enc_disable_sensor_clock();
            video_encode_preview_on();
            /* sensorぃ闽,盢sensor 癳戈ま旧┏糷preview flow */
            ap_video_capture_mode_switch(0, STATE_VIDEO_PREVIEW);
            break;

        case MSG_APQ_NIGHT_MODE_KEY:
            audio_effect_play(EFFECT_CLICK);
            ap_state_handling_night_mode_switch();
            break;

        case MSG_APQ_USER_CONFIG_STORE:
            ap_state_config_store();
            break;

        case MSG_APQ_AUDIO_EFFECT_UP:
        case MSG_APQ_AUDIO_EFFECT_DOWN:
            break;

        case MSG_APQ_HDMI_PLUG_IN:
            if(pic_flag == 0)
            {
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
                vid_enc_disable_sensor_clock();
                OSQPost(StateHandlingQ, (void *) STATE_BROWSE);
                msgQSend(ApQ, MSG_APQ_HDMI_PLUG_IN, NULL, NULL, MSG_PRI_NORMAL);
                exit_flag = EXIT_BREAK;
            }
            else
            {
                pic_flag = 5;
            }
            break;


        //+++ TV_OUT_D1
        case MSG_APQ_TV_PLUG_OUT:
        case MSG_APQ_TV_PLUG_IN:
            video_capture_resolution_clear();
            left_capture_num_str_clear();

            if(pic_flag == 0)
            {
                ap_state_handling_str_draw_exit();
                OSTimeDly(3);
                vid_enc_disable_sensor_clock();
                if(msg_id == MSG_APQ_TV_PLUG_IN)
                {
                    ap_state_handling_tv_init();
                }
                else
                {
                    ap_state_handling_tv_uninit();
                }
                ap_video_capture_mode_switch(0, STATE_VIDEO_PREVIEW);
                video_capture_resolution_display();
                left_capture_num = cal_left_capture_num();
                left_capture_num_display(left_capture_num);
            }
            else
            {
                if(msg_id == MSG_APQ_TV_PLUG_IN)
                {
                    pic_flag = 6;
                }
                else
                {
                    pic_flag = 7;
                }
            }
            break;
        //---

        default:
            ap_state_common_handling(msg_id);
            break;
        }
    }

    state_video_preview_exit();
    if(photo_check_time_flag)
    {
        timer_stop(TIMER_C);
    }
}

void state_video_preview_exit(void)
{
#if GPDV_BOARD_VERSION != GPCV1237A_Aerial_Photo
    ap_video_preview_exit();
#endif

    DBG_PRINT("Exit video_preview state\r\n");
}

/*****************************************************************************
 * 函 数 名  : state_video_capute_moto_led_ctl
 * 负 责 人  : Zhibo
 * 创建日期  : 2017年5月4日
 * 函数功能  : 拍照时马达和灯控制
 * 输入参数  : void  NULL
 * 输出参数  : 无
 * 返 回 值  : 
 * 调用关系  : 
 * 其    它  : 

*****************************************************************************/
void state_video_capute_moto_led_ctl(void)
{
	moto_vibration_on();
	led_red_on();
	OSTimeDly(25);
	
	moto_vibration_off();
	led_red_off();
}



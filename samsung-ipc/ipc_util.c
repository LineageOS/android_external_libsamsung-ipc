/**
 * This file is part of libsamsung-ipc.
 *
 * Copyright (C) 2010-2011 Joerie de Gram <j.de.gram@gmail.com>
 *
 * libsamsung-ipc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libsamsung-ipc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libsamsung-ipc.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <radio.h>
#include <string.h>

#define IPC_STR(f)	case f: return strdup(#f);

const char *ipc_response_type_to_str(int type) {
	switch(type) {
		case IPC_TYPE_INDI:
			return "INDI";
		case IPC_TYPE_RESP:
			return "RESP";
		case IPC_TYPE_NOTI:
			return "NOTI";
		default:
			return "UNKNOWN";
	}
}

const char *ipc_command_type_to_str(int command) {
	switch(command) {
		IPC_STR(IPC_PWR_PHONE_PWR_UP)
		IPC_STR(IPC_PWR_PHONE_PWR_OFF)
		IPC_STR(IPC_PWR_PHONE_RESET)
		IPC_STR(IPC_PWR_BATT_STATUS)
		IPC_STR(IPC_PWR_BATT_TYPE)
		IPC_STR(IPC_PWR_BATT_COMP)
		IPC_STR(IPC_PWR_PHONE_STATE)
		IPC_STR(IPC_CALL_OUTGOING)
		IPC_STR(IPC_CALL_INCOMING)
		IPC_STR(IPC_CALL_RELEASE)
		IPC_STR(IPC_CALL_ANSWER)
		IPC_STR(IPC_CALL_STATUS)
		IPC_STR(IPC_CALL_LIST)
		IPC_STR(IPC_CALL_BURST_DTMF)
		IPC_STR(IPC_CALL_CONT_DTMF)
		IPC_STR(IPC_CALL_WAITING)
		IPC_STR(IPC_CALL_LINE_ID)
		IPC_STR(IPC_SMS_SEND_MSG)
		IPC_STR(IPC_SMS_INCOMING_MSG)
		IPC_STR(IPC_SMS_READ_MSG)
		IPC_STR(IPC_SMS_SAVE_MSG)
		IPC_STR(IPC_SMS_DEL_MSG)
		IPC_STR(IPC_SMS_DELIVER_REPORT)
		IPC_STR(IPC_SMS_DEVICE_READY)
		IPC_STR(IPC_SMS_SEL_MEM)
		IPC_STR(IPC_SMS_STORED_MSG_COUNT)
		IPC_STR(IPC_SMS_SVC_CENTER_ADDR)
		IPC_STR(IPC_SMS_SVC_OPTION)
		IPC_STR(IPC_SMS_MEM_STATUS)
		IPC_STR(IPC_SMS_CBS_MSG)
		IPC_STR(IPC_SMS_CBS_CONFIG)
		IPC_STR(IPC_SMS_STORED_MSG_STATUS)
		IPC_STR(IPC_SMS_PARAM_COUNT)
		IPC_STR(IPC_SMS_PARAM)
		IPC_STR(IPC_SEC_PIN_STATUS)
		IPC_STR(IPC_SEC_PHONE_LOCK)
		IPC_STR(IPC_SEC_CHANGE_LOCKING_PW)
		IPC_STR(IPC_SEC_SIM_LANG)
		IPC_STR(IPC_SEC_RSIM_ACCESS)
		IPC_STR(IPC_SEC_GSIM_ACCESS)
		IPC_STR(IPC_SEC_SIM_ICC_TYPE)
		IPC_STR(IPC_SEC_LOCK_INFO)
		IPC_STR(IPC_SEC_ISIM_AUTH)
		IPC_STR(IPC_PB_ACCESS)
		IPC_STR(IPC_PB_STORAGE)
		IPC_STR(IPC_PB_STORAGE_LIST)
		IPC_STR(IPC_PB_ENTRY_INFO)
		IPC_STR(IPC_PB_CAPABILITY_INFO)
		IPC_STR(IPC_DISP_ICON_INFO)
		IPC_STR(IPC_DISP_HOMEZONE_INFO)
		IPC_STR(IPC_NET_PREF_PLMN)
		IPC_STR(IPC_NET_PLMN_SEL)
		IPC_STR(IPC_NET_CURRENT_PLMN)
		IPC_STR(IPC_NET_PLMN_LIST)
		IPC_STR(IPC_NET_REGIST)
		IPC_STR(IPC_NET_SUBSCRIBER_NUM)
		IPC_STR(IPC_NET_BAND_SEL)
		IPC_STR(IPC_NET_SERVICE_DOMAIN_CONFIG)
		IPC_STR(IPC_NET_POWERON_ATTACH)
		IPC_STR(IPC_NET_MODE_SEL)
		IPC_STR(IPC_NET_ACQ_ORDER)
		IPC_STR(IPC_NET_IDENTITY)
		IPC_STR(IPC_NET_CURRENT_RRC_STATUS)
		IPC_STR(IPC_MISC_ME_VERSION)
		IPC_STR(IPC_MISC_ME_IMSI)
		IPC_STR(IPC_MISC_ME_SN)
		IPC_STR(IPC_MISC_TIME_INFO)
		IPC_STR(IPC_SS_WAITING)
		IPC_STR(IPC_SS_CLI)
		IPC_STR(IPC_SS_BARRING)
		IPC_STR(IPC_SS_BARRING_PW)
		IPC_STR(IPC_SS_FORWARDING)
		IPC_STR(IPC_SS_INFO)
		IPC_STR(IPC_SS_MANAGE_CALL)
		IPC_STR(IPC_SS_USSD)
		IPC_STR(IPC_SS_AOC)
		IPC_STR(IPC_SS_RELEASE_COMPLETE)
		IPC_STR(IPC_GPRS_DEFINE_PDP_CONTEXT)
		IPC_STR(IPC_GPRS_QOS)
		IPC_STR(IPC_GPRS_PS)
		IPC_STR(IPC_GPRS_PDP_CONTEXT)
		IPC_STR(IPC_GPRS_SHOW_PDP_ADDR)
		IPC_STR(IPC_GPRS_MS_CLASS)
		IPC_STR(IPC_GPRS_3G_QUAL_SERVICE_PROFILE)
		IPC_STR(IPC_GPRS_IP_CONFIGURATION)
		IPC_STR(IPC_GPRS_DEFINE_SEC_PDP_CONTEXT)
		IPC_STR(IPC_GPRS_TFT)
		IPC_STR(IPC_GPRS_HSDPA_STATUS)
		IPC_STR(IPC_GPRS_CURRENT_SESSION_DATA_COUNT)
		IPC_STR(IPC_GPRS_DATA_DORMANT)
		IPC_STR(IPC_GPRS_DUN_PIN_CTRL)
		IPC_STR(IPC_GPRS_CALL_STATUS)
		IPC_STR(IPC_SAT_PROFILE_DOWNLOAD)
		IPC_STR(IPC_SAT_ENVELOPE_CMD)
		IPC_STR(IPC_SAT_PROACTIVE_CMD)
		IPC_STR(IPC_SAT_TERMINATE_USAT_SESSION)
		IPC_STR(IPC_SAT_EVENT_DOWNLOAD)
		IPC_STR(IPC_SAT_PROVIDE_LOCAL_INFO)
		IPC_STR(IPC_SAT_POLLING)
		IPC_STR(IPC_SAT_REFRESH)
		IPC_STR(IPC_SAT_SETUP_EVENT_LIST)
		IPC_STR(IPC_SAT_CALL_CONTROL_RESULT)
		IPC_STR(IPC_SAT_IMAGE_CLUT)
		IPC_STR(IPC_SAT_CALL_PROCESSING)
		IPC_STR(IPC_IMEI_START)
		IPC_STR(IPC_IMEI_CHECK_DEVICE_INFO)
		IPC_STR(IPC_GEN_PHONE_RES)
		default:
			return "IPC_UNKNOWN";
	}
}


/*************************************************************************
*	System		: POPLAR/ANZU_L
*	File Name	: LST_DCMD.C
*	Author		: 桑原 美紀
*	Date		: 1997/03/11
*	RealTimeOS	: ＲＩＳＣ（ＳＨ７０４３）モニター
*	Description	: 通信予約消去通知
*	Maintenance	: 
*
*	Copyright (C) 1996 Murata Machinery,Ltd. All rights reserved.
*************************************************************************/
#include	"\src\atlanta\define\product.h"
#include	"\src\atlanta\define\apl_msg.h"
#include	"\src\atlanta\define\std.h"

#include	"\src\atlanta\define\cmn_def.h"
#include	"\src\atlanta\define\lst_def.h"

#include	"\src\atlanta\define\cmn_pro.h"
#include	"\src\atlanta\define\lst_pro.h"

#include	"\src\atlanta\ext_v\bkupram.h"
#include	"\src\atlanta\ext_v\lst_data.h"
#include	"\src\atlanta\ext_v\lst_wrd.h"
#include	"\src\atlanta\ext_v\sys_data.h"

#if (PRO_CONTINUOUS_POLLING == ENABLE) /* 連続ポーリング機能追加 1996/10/18 Eguchi */
#include	"\src\atlanta\define\syscntpl.h" /* 1996/10/16 Eguchi */
#endif

/*************************************************************************
	module		:[通信予約消去通知印刷]
	function	:[通信予約消去通知を印刷する]
	common		:[
		List			:
		SYB_CommandFile	:
		SYB_BatchTxFile	:
		SYS_ScannerComEraseRequest:
	]
	condition	:[]
	commment	:[
		修正履歴
		'94.10/20	   行目:"ﾂｳｼﾝﾖﾔｸ ｺﾏﾝﾄﾞｶﾞ ｼｮｳｷｮ ｻﾚﾏｼﾀ .............."
							の印字の時、他の消去通知と同じように、
							枠で囲むように変更した
		'94.10/27		一括送信機能が有りで、一括送信原稿が消去された時、
							"一括送信原稿が消去されました．．．"を印字する
		'94.11/22		他のリストと合わせるため、日時の後の改行をなくした。
						by j.masuda
		'94.11/26		コマンドファイルのステータスをEMPTYにする前に
						SYS_ScannerComEraseListRequestをクリアーする。
						PRO_DRAM_BACKUP==ENABLEの時のみ。
						By j.masuda
		'94.12/24		'94.11/26の変更が、SATUKI/LVNDRの条件コンパイル中に
						入っており、KIRI/MOMIJIの条件コンパイルには、入って
						いなかった為、KIRI/MOMIJIにもいれた。
	]
	return		:[印刷結果]
	machine		:[SH7043]
	language	:[SHC]
	keyword		:[LST]
	date		:[93/11/25]
	author		:[増田次郎]
*************************************************************************/
WORD				Print_DelReserveCmd_Notice(
						 void )				/*なし*/
{
	UBYTE	i;						/*loop*/
	register WORD	ret;					/*実行結果*/

/* 以下１１行を連続ポーリング機能のため追加 1996/10/18 Eguchi */
	UWORD	status;
	status = Check_AnyList(LST_DELRESERVECMD_NOTICE);
#if (PRO_BATCH_TX == ENABLE)
	status &= Check_AnyList(LST_DELBATCHTXDOC_NOTICE);
#endif
#if (PRO_CONTINUOUS_POLLING == ENABLE)
	status &= Check_AnyList(LST_DELCONTPOLLCMD_NOTICE);
#endif
	if (status == MSG_PRN_LST_NO_LIST) {
		return (MSG_PRN_LST_NO_LIST);
	}
/* 以上１１行を連続ポーリング機能のため追加 1996/10/18 Eguchi  */

	if ( (ret = CharacterPrint( LST_OPEN )) != OK ) {
		return ( ret );
	}

	/*１改行＋発信元名、番号印刷＋２改行*/
	if ( (ret = TTI_ID_Print_Feed()) != OK ) {
		return ( ret );
	}

	/*�ｮ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｲ*/
	Prn_Att_Str_Clear( List.S.Print, List.S.Attribute );
	List.S.Print[21-1] = LST_KLINE7;
	CMN_MemorySet( &List.S.Print[22-1], 38, LST_KLINE_ );
	List.S.Print[60-1] = LST_KLINE9;
	if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
		return ( ret );
	}

	/*＊＊　ツウシンヨヤク　ショウキョ　ツウチ　＊＊*/
	Prn_Att_Str_Clear( List.S.Print, List.S.Attribute );
	List.S.Print[21-1] = LST_KLINEI;
#if ( PRO_PANEL == KANJI ) || ( PRO_JIS_CODE == ENABLE )
		AttributeSet( &List.S.Print[24-1], &List.S.Attribute[24-1],
		 PWRD_ErasedCommands_K, LST_NOT);		/* MES→INV 94.7.20 -> NOT 8.10 */
#else
	AttributeSet( &List.S.Print[24-1], &List.S.Attribute[24-1],
	  PWRD_ErasedCommands, LST_MES_TWI_XXX );

#endif

	List.S.Print[60-1] = LST_KLINEI;
	if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
		return ( ret );
	}

	/*�ｶ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｺ*/
	Prn_Att_Str_Clear( List.S.Print, List.S.Attribute );
	List.S.Print[21-1] = LST_KLINE1;
	CMN_MemorySet( &List.S.Print[22-1], 38, LST_KLINE_ );
	List.S.Print[60-1] = LST_KLINE3;
	if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
		return ( ret );
	}

	/*１行印字（改行）*/
	if ( (ret = CharacterPrint( LST_LINE_FEED )) != OK ) {
		return ( ret );
	}

	/*現在時間*/
	if ( (ret = CurrentTimePrint( 60-1 )) != OK ) {
		return ( ret );
	}

#if ( PRO_BATCH_TX == ENABLE )	/* 通信予約消去通知に一括送信原稿消去も記載する 94.10.27 Toyoda */
	for ( i = 0; i < SYS_COM_FILE_MAX; i++ ) {
 #if (PRO_COMMANDFILE_SRAM == ENABLE)	/* M.Tachibana 1997/03/22 */
		if ( SYB_CommandFile[i].Status == SYS_CMD_POWER_OFF ) {
 #else
		if ( SYB_CommandStatus[i] == SYS_CMD_POWER_OFF ) {
 #endif
			/*�ｮ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｲ '94.10/20 By K.Watanabe*/
			Print_DelPoll_List_Line( 0, List.S.Print, List.S.Attribute );
			if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
				return ( ret );
			}

			/*�､ﾂｳｼﾝﾖﾔｸｹﾞﾝｺｳｶﾞ　ｼｮｳｷｮ　ｻﾚﾏｼﾀ ................. �､*/
			Print_DelPoll_List_Line( 1, List.S.Print, List.S.Attribute );	/* '94.10/20 By K.Watanabe */
			AttributeSet( &List.S.Print[2-1], &List.S.Attribute[2-1], PWRD_ThisComErased, LST_NOT );
			if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
				return ( ret );
			}

			/*�ｶ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｺ '94.10/20 By K.Watanabe*/
			Print_DelPoll_List_Line( 2, List.S.Print, List.S.Attribute );
			if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
				return ( ret );
			}
			/*１行印字（改行）*/
			if ( (ret = CharacterPrint( LST_LINE_FEED )) != OK ) {
				return ( ret );
			}
			break;
		}
	}
	for ( i = 0; i < SYS_BATCH_FILE_MAX; i++ ) {
		if ( SYB_BatchTxFile[i].Status == SYS_CMD_POWER_OFF ) {
			/*�ｮ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｲ '94.10/20 By K.Watanabe*/
			Print_DelPoll_List_Line( 0, List.S.Print, List.S.Attribute );
			if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
				return ( ret );
			}

			/*�､一括送信原稿が消去されました ................. �､*/
			Print_DelPoll_List_Line( 1, List.S.Print, List.S.Attribute );	/* '94.10/20 By K.Watanabe */
			AttributeSet( &List.S.Print[2-1], &List.S.Attribute[2-1], PWRD_BatchTxDocErase, LST_NOT );
			if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
				return ( ret );
			}

			/*�ｶ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｺ '94.10/20 By K.Watanabe*/
			Print_DelPoll_List_Line( 2, List.S.Print, List.S.Attribute );
			if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
				return ( ret );
			}
			/*１行印字（改行）*/
			if ( (ret = CharacterPrint( LST_LINE_FEED )) != OK ) {
				return ( ret );
			}
			break;
		}
	}
 #if (PRO_CONTINUOUS_POLLING == ENABLE) /* 連続ポーリング機能追加 1996/10/18 Eguchi */
	if (SYB_ContinuousPolling.Status == SYS_CMD_POWER_OFF) {/*いらんやろ*/

		Print_DelPoll_List_Line( 0, List.S.Print, List.S.Attribute );
		if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
			return ( ret );
		}

		/* 連続ポーリング原稿が消去されました・・・・・ */
		Print_DelPoll_List_Line( 1, List.S.Print, List.S.Attribute );
		AttributeSet( &List.S.Print[2-1], &List.S.Attribute[2-1], PWRD_ContinuousPollingErase, LST_NOT );
		if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
			return ( ret );
		}

		/*�ｶ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｺ '94.10/20 By K.Watanabe*/
		Print_DelPoll_List_Line( 2, List.S.Print, List.S.Attribute );
		if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
			return ( ret );
		}
		/*１行印字（改行）*/
		if ( (ret = CharacterPrint( LST_LINE_FEED )) != OK ) {
			return ( ret );
		}
	}
 #endif

 #if (PRO_DRAM_BACKUP == ENABLE)			/*94/12/24 ↓ By jmasuda*/
	SYS_ScannerComEraseListRequest = 0;
 #endif									/*94/12/24 ↑ By jmasuda*/
	for ( i = 0; i < SYS_COM_FILE_MAX; i++ ) {
 #if (PRO_COMMANDFILE_SRAM == ENABLE)	/* M.Tachibana 1997/03/22 */
		if ( SYB_CommandFile[i].Status == SYS_CMD_POWER_OFF ) {
			SYB_CommandFile[i].Status = SYS_CMD_EMPTY;

	#if (PRO_F_CODE == ENABLE)
			if (CMN_CheckFcodeCommand(SYB_CommandFile[i].Option.Item) == TRUE) {	/** 交信種別判断 */
				SYB_FcodeNumberCDataBuffer[SYB_CommandFile[i].Option.OptionNumber.FcodeDataPosition[0]].SYS_SubAddressNumber[0] = 0xFF;
				SYB_FcodeNumberCDataBuffer[SYB_CommandFile[i].Option.OptionNumber.FcodeDataPosition[0]].SYS_PassWordNumber[0] = 0xFF;
			}
	#endif
		}
 #else
		if ( SYB_CommandStatus[i] == SYS_CMD_POWER_OFF ) {
			SYB_CommandFile[i].Status = SYS_CMD_EMPTY;
	#if (PRO_F_CODE == ENABLE)
			if (CMN_CheckFcodeCommand(SYB_CommandFile[i].Option.Item) == TRUE) {	/** 交信種別判断 */
				SYB_FcodeNumberCDataBuffer[SYB_CommandFile[i].Option.OptionNumber.FcodeDataPosition[0]].SYS_SubAddressNumber[0] = 0xFF;
				SYB_FcodeNumberCDataBuffer[SYB_CommandFile[i].Option.OptionNumber.FcodeDataPosition[0]].SYS_PassWordNumber[0] = 0xFF;
			}
	#endif
			SYB_CommandStatus[i] = SYS_CMD_EMPTY;
		}
 #endif
	}
	for ( i = 0; i < SYS_BATCH_FILE_MAX; i++ ) {
		if ( SYB_BatchTxFile[i].Status == SYS_CMD_POWER_OFF ) {
			SYB_BatchTxFile[i].Status = SYS_CMD_EMPTY;
/*			for ( j = 0; j < SYS_BATCH_INDEX_MAX; j++ ) {	0ｸﾘｱはｵﾍﾟﾚｰｼｮﾝがする '94.11.16 H.T */
/*				SYB_BatchTxFile[i].IndexNo[j] = 0x0000;		*/
/*			}												*/
		}
	}

 #if (PRO_CONTINUOUS_POLLING == ENABLE) /* 連続ポーリング処理追加 1996/10/18 Eguchi */
	if (SYB_ContinuousPolling.Status == SYS_CMD_POWER_OFF) {
		SYB_ContinuousPolling.Status = SYS_CMD_EMPTY;
	}
 #endif


#else
 #if (PRO_DRAM_BACKUP == ENABLE)			/*94/11/26 ↓ By jmasuda*/
	SYS_ScannerComEraseListRequest = 0;
 #endif									/*94/11/26 ↑ By jmasuda*/
	for ( i = 0; i < SYS_COM_FILE_MAX; i++ ) {
 #if (PRO_COMMANDFILE_SRAM == ENABLE)	/* M.Tachibana 1997/03/22 */
		if ( SYB_CommandFile[i].Status == SYS_CMD_POWER_OFF ) {
			SYB_CommandFile[i].Status = SYS_CMD_EMPTY;
	#if (PRO_F_CODE == ENABLE)
			if (CMN_CheckFcodeCommand(SYB_CommandFile[i].Option.Item) == TRUE) {	/** 交信種別判断 */
				SYB_FcodeNumberCDataBuffer[SYB_CommandFile[i].Option.OptionNumber.FcodeDataPosition[0]].SYS_SubAddressNumber[0] = 0xFF;
				SYB_FcodeNumberCDataBuffer[SYB_CommandFile[i].Option.OptionNumber.FcodeDataPosition[0]].SYS_PassWordNumber[0] = 0xFF;
			}
	#endif
		}
 #else
		if ( SYB_CommandStatus[i] == SYS_CMD_POWER_OFF ) {
			SYB_CommandFile[i].Status = SYS_CMD_EMPTY;
	#if (PRO_F_CODE == ENABLE)
			if (CMN_CheckFcodeCommand(SYB_CommandFile[i].Option.Item) == TRUE) {	/** 交信種別判断 */
				SYB_FcodeNumberCDataBuffer[SYB_CommandFile[i].Option.OptionNumber.FcodeDataPosition[0]].SYS_SubAddressNumber[0] = 0xFF;
				SYB_FcodeNumberCDataBuffer[SYB_CommandFile[i].Option.OptionNumber.FcodeDataPosition[0]].SYS_PassWordNumber[0] = 0xFF;
			}
	#endif
			SYB_CommandStatus[i] = SYS_CMD_EMPTY;
		}
 #endif
	}
	/*�ｮ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｲ '94.10/20 By K.Watanabe*/
	Print_DelPoll_List_Line( 0, List.S.Print, List.S.Attribute );
	if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
		return ( ret );
	}

	/*�､ﾂｳｼﾝﾖﾔｸｹﾞﾝｺｳｶﾞ　ｼｮｳｷｮ　ｻﾚﾏｼﾀ ................. �､*/
	Print_DelPoll_List_Line( 1, List.S.Print, List.S.Attribute );	/* '94.10/20 By K.Watanabe */
	AttributeSet( &List.S.Print[2-1], &List.S.Attribute[2-1], PWRD_ThisComErased, LST_NOT );
	if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
		return ( ret );
	}

	/*�ｶ�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�｢�ｺ '94.10/20 By K.Watanabe*/
	Print_DelPoll_List_Line( 2, List.S.Print, List.S.Attribute );
	if ( (ret = CharacterPrint( LST_PRINT )) != OK ) {
		return ( ret );
	}
	/*１行印字（改行）*/
	if ( (ret = CharacterPrint( LST_LINE_FEED )) != OK ) {
		return ( ret );
	}
#endif

	if ( (ret = CharacterPrint( LST_CLOSE )) != OK ) {
		return ( ret );
	}
	return ( OK );
}


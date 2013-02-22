   #define _IRPowOFF   0x00
   #define _IRPowON    0x01
   #define _IrDAPowON  0x05
   #define _IRPowStat  0x02

   extern unsigned char IRPowerCtrl(unsigned char ctrl);
/*
1.�� �� �� Դ �� ��
�� ��:
     ctrl
        _IRPowOFF      �رպ����Դ������Ϊ����ģʽ
        _IRPowON       �򿪺����Դ������Ϊ�պ���ģʽ
        _IrDAPowON     �򿪺����Դ������ΪIrDAģʽ
        _IRPowStat     ��ȡ�����Դ״̬
�� �� �� �� :
	��
�� �� ֵ :
	0 �� ״ ̬ Ϊ �� ��
	1 �� ״ ̬ Ϊ �� ��
*/



   extern void SetIRMFreq(long freq);
/*
2.�� �� �� �� �� �� Ƶ ��
�� ��:
	freq
	  �� Hz Ϊ �� λ �� Ƶ �� ֵ �� 38000 Hz��
	  0 �� ʾ �� �� �� �� �� �� Ƶ �ʣ�ʹ �� ��
	       ֮ �� �� �� �� �գ�
�� �� �� �� :
	��
�� �� ֵ :
	��
*/


   extern void SetIROutput(unsigned char io);
/*
3.�� �� �� �� �� ��
�� ��:
	io
	  0  �� �� �� �� ƽ
	  1  �� �� �� �� ƽ
	  2  �� �� �� �� �� �� �� ��(ȷ ʡ) ,
 	     �� �� �� �� �� Ϊ COM2�� ��� �� ȫ
	     �� COM2 �� �� ��
�� �� �� �� :
	��
�� �� ֵ :
	��
*/


   extern unsigned char GetIRInput(void);
/*
4.ȡ ��  �� �� �� ��
�� ��:
	��  �
�� �� �� �� :
	��
�� �� ֵ :
	0 Ϊ �� �� ƽ
	1 Ϊ �� �� ƽ
*/

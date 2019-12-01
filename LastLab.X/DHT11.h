/* 
 * File:   DHT.h
 * Author: khoanguyen
 *
 * Created on November 22, 2019, 4:12 PM
 */

#ifndef DHT_H
#define	DHT_H
#define Data_Out LATCbits.LATC0
#define Data_In PORTCbits.RC0
#define Data_Dir TRISCbits.TRISC0
//#define _XTAL_FREQ 10000000
#define DHT_TO 10000
char RH_Decimal = 0, RH_Integral = 0, T_Decimal = 0, T_Integral = 0;
char Checksum;
char value[10];
void DHT_Init(void);
void DHT_Check(void);
char DHT_ReadData(void);
void DHT_Result(void);
#endif	/* DHT_H */


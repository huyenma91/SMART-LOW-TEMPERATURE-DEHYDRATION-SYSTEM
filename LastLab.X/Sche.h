/* 
 * File:   Sched_1.h
 * Author: DELL
 *
 * Created on November 24, 2019, 2:12 PM
 */

#ifndef SCHED_1_H
#define	SCHED_1_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
void start(void);
void insert(int delay, int period, void (*func_ptr)()); 
void remove(void);      
void update(void);
void deleteTask(void (*func_ptr)());
void dispatch(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SCHED_1_H */


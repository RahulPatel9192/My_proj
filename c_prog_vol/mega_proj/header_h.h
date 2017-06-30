/*Copyright(c) <2016>, Volansys Technologies 
 *  * 
 *  Description: 
 * @header_h.h   
 * @In this all Header files, Macroes and Function definations are added releted 
 *  to rail reservation system project.
 *    
 *  
 * Author       - Rahul Patel 
 * 
 ********************************************************************************** 
 *  
 * History 
 *
 * Aug/29/2016, Rahul P 
 *                      
 * Aug/29/2016, Rahul P, Created (description) 
 * 
 *******************************************************************************/ 

#ifndef header_h 
#define header_h 

/* All Heade files include */
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <math.h>

/* Macros used in different modules */
#define TRAINNAME 50 /* length of tharin name */
#define SOURCE 50 /* length of sourcr station name */
#define DEST 50 /* length of destination station name */
#define STATION_NU 10 /* number of total stations */
#define DISTANCE 1000 /* total distance */
#define UNAME "admin" /* admin username*/
#define PW "123"  /* admmin password */

/* TrainInfo: function gives train releted info to the user 
 * it take NULL argumentd and return type is void (NULL)*/
void TrainInfo();

/* Reservation: doing reservation releted things like book a ticket, taking details
 * to the customer ,giving ticket number and seat number. return type of the function
 * is integer it return zero or one */
int Reservation();

/* edittraininfo: edit train releted information i.e add new train ,
 * delete exsisting train and edit existing train information 
 * this function return integer that is zero or one */
int edittraininfo();

/* TrainInfoNumber: check train is present or not according to train number.
 * input argument is train number that is in integer foramt and return zero or one in
 * integer datatype.
 * @int Train number */
int TrainInfoNumber( int );

/* TrainInfoName: check train is present or not according to train name.
 * input argument is train name that is in char pointer format and return zero or one in
 * integer datatype.
 * @char* Train name */
int TrainInfoName( char * );

/* TrainInfoStation: check train is present or not according to source and
 * destination stations, input argument is source and destination statios in 
 * char pointer format it return integer which is zero or one.
 * @char* source station name 
 * @char* Destination station name */
int TrainInfoStation( char *, char *);

/* LoginModule: doing login and signup process
 * @detailed Description: function use before reservation process start if user is valid
 * then and then only user can booked a ticket. 
 * @char* username
 * @char* password
 * @int login option
 * retrun 1 or 0*/
int LoginModule(char *, char *, int );

#endif  /* '#endif' of header_h */                                                       

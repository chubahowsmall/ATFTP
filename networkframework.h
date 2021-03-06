/***************************************************************************
 *   Copyright (C) 2009 by Ammar Qammaz, Ivan kanakarakis                  *
 *   ammarkov@gmail.com                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _NETWORKFRAMEWORK_H_
#define _NETWORKFRAMEWORK_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/uio.h> 
#include <regex.h>

#define ROOT_ID 0
#define DEF_SERV_PORT 69
#define MAX_FAILED_RETRIES 10
#define ARG_READ "-r"
#define ARG_WRITE "-w"
#define ARG_START_SERVR "-s"
#define ADDRESS_PATTERN "^\\([0-9]\\{1,3\\}\\.\\)\\{3\\}[0-9]\\{1,3\\}$"
#define PORT_PATTERN "^[0-9]\\{1,5\\}$"

enum client_mode
{
  READ = 1, WRITE
};

struct TFTP_PACKET //  <- XWRAEI OPOIODIPOTE ALLO PAKETO AN DN KSEROUME TI EINAI
{
  unsigned char Op1, Op2;
  char data[514];
};

struct DATA_TFTP_PACKET //  <- GIA DATA PAKETA 
{
  unsigned char Op1, Op2;
  unsigned short Block;
  char data[512];
};

struct ACK_TFTP_PACKET //  <- GIA ACKNOWLEDGMENT PAKETA 
{
  unsigned char Op1, Op2;
  unsigned short Block;
  char data[512];
};

struct ERROR_TFTP_PACKET //  <- XWRAEI OPOIODIPOTE ALLO PAKETO AN DN KSEROUME TI EINAI
{
  unsigned char Op1, Op2;
  unsigned short ErrorCode;
  char data[512];
};

unsigned int MINDATAPORT;
unsigned int MAXDATAPORT;
unsigned short verbosity;

int TFTPServer(unsigned int port);
int TFTPClient(char * server, unsigned int port, char * filename, int operation);

#endif

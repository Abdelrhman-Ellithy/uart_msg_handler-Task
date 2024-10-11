/*
 * uart_msg_handler.h
 * Created: 2024-10-9
 *  Author: Abdelrahman Ellithy
 */ 

#ifndef UART_MSG_HANDLER_H
#define UART_MSG_HANDLER_H

#define MAGIC_PATTERN_BYTE1 'T'
#define MAGIC_PATTERN_BYTE2 'W'

typedef void (*tpf_uart_msg_handler_recv_cb)(char *msg_buf, int msg_length);

void uart_handler_init(char uart_channel_num, tpf_uart_msg_handler_recv_cb pf_uart_msg_handler_recv_cb);
void uart_send_msg(char *msg_buf, int msg_length);

#endif /* UART_MSG_HANDLER_H */

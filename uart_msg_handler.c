/*
 * uart_msg_handler.c
 * Created: 2024-10-9
 *  Author: Abdelrahman Ellithy
 */ 

#include "uart.h"
#include "uart_msg_handler.h"

static char msg_buf[256];
static int msg_buf_index = 0;
static int msg_length = 0;
static tpf_uart_msg_handler_recv_cb app_callback = NULL;

static void uart_recevied_msg_cb(char received_char) {
    
    if (msg_buf_index == 0 && received_char == MAGIC_PATTERN_BYTE1) {
        msg_buf[msg_buf_index++] = received_char; 
    } 
    else if (msg_buf_index == 1 && received_char == MAGIC_PATTERN_BYTE2) {
        msg_buf[msg_buf_index++] = received_char; 
    } 
    else if (msg_buf_index == 2) {
        msg_length = (int)received_char << 8;
        msg_buf[msg_buf_index++] = received_char;
    } 
    else if (msg_buf_index == 3) {
        msg_length |= (int)received_char;
        msg_buf[msg_buf_index++] = received_char;
    } 
    else if (msg_buf_index > 3 && msg_buf_index < (msg_length + 4)) {
        msg_buf[msg_buf_index++] = received_char;
        
        if (msg_buf_index == (msg_length + 4)) {
            if (app_callback) {
                app_callback(msg_buf, msg_length); 
            }
            msg_buf_index = 0; 
        }
    } 
    else {
        msg_buf_index = 0;
    }
}

void uart_handler_init(char uart_channel_num, tpf_uart_msg_handler_recv_cb pf_uart_msg_handler_recv_cb) {
    uart_init(uart_channel_num, uart_recevied_msg_cb); 
    app_callback = pf_uart_msg_handler_recv_cb; 
}

void uart_send_msg(char *msg_buf, int msg_length) {
    uart_send(msg_buf, msg_length);
}

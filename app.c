/*
 * app.c
 * Created: 2024-10-9
 *  Author: Abdelrahman Ellithy
 */ 
#include "uart_msg_handler.h"
#include "lcd.h"
#include "app.h"

static void print_msg_cb(char *msg_buf, int msg_length) {
    log("data_length = %d.\n", msg_length);
    log("data =\n");

    int print_counter = 0;

    while (print_counter < msg_length) {
        printf("%02hhx ", msg_buf[print_counter]);
        print_counter++;

        if (print_counter % 16 == 0) {
            log("\n");
        }
    }
    log("\n");
}

static void app_init() {
    // Initialize the UART handler and pass the print_msg_cb as the callback
    uart_handler_init(1, print_msg_cb);
}

int main() {
    app_init();
    while (1);
    return 0;
}

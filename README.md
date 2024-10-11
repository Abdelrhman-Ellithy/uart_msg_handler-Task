# UART Communication Protocol between TWI Devices 🚀

**UART Communication Handler**! a simple implementation of a UART communication protocol for TWI devices, where the **UART HAL** receives messages and passes them to the application layer for processing.

## Project Overview

This project consists of three main components:
1. **UART Message Handler** (`uart_msg_handler.c` and `uart_msg_handler.h`) – responsible for handling UART message reception, validation, and passing data to the application layer.
2. **Application Layer** (`app.c`) – processes the received messages and prints them.
3. **UART HAL** (`uart.c` - not included) – the hardware abstraction layer that interacts with the physical UART and triggers message reception callbacks.

## File Structure 📁

- `uart_msg_handler.c` – Handles the received UART messages and validates them.
- `uart_msg_handler.h` – Defines the message structure, magic bytes, and callback function types.
- `app.c` – Implements the application callback to process and display received messages.

## How it Works 🤖

1. **UART HAL** invokes the callback `uart_recevied_msg_cb()` every time a character is received.
2. The **UART Message Handler** (`uart_msg_handler.c`) processes the message byte by byte:
   - Checks for valid **magic pattern bytes** to identify the start of a message.
   - Reads the message length and collects data bytes.
   - Once a full message is received, the handler triggers the application callback function.
3. The **Application Layer** (`app.c`) defines the `print_msg_cb()` function, which logs the message length and content in hexadecimal format.

### Example Flow:

- UART receives a message starting with the magic bytes **`'T'`** and **`'W'`**.
- The handler processes the message, validates it, and passes it to the application layer.
- The application prints the message in a structured format.

## Setup and Usage 🔧

### 1. Clone the Repository

```bash
git clone https://github.com/your-repo-name/uart-communication-handler.git
```

### 2. Build the Project

Compile the source code using your preferred C compiler.

### 3. Run the Application

The application will continuously wait for UART messages, process them, and print the results.

```bash
./your_project_executable
```

## Code Details 🧑‍💻

### UART Message Handler (`uart_msg_handler.c`)

- **`uart_recevied_msg_cb()`**: This callback function is triggered by the UART HAL when a character is received. It checks for valid magic bytes and processes the message.
- **`uart_handler_init()`**: Initializes the UART handler and sets up the callback function.
- **`uart_send_msg()`**: Sends a message through UART.

### Application Layer (`app.c`)

- **`print_msg_cb()`**: Callback function that logs the received message in hexadecimal format.

### Header File (`uart_msg_handler.h`)

- Defines the magic bytes: 
  - `MAGIC_PATTERN_BYTE1 = 'T'`
  - `MAGIC_PATTERN_BYTE2 = 'W'`
- Declares the callback type `tpf_uart_msg_handler_recv_cb` and functions for initializing and sending messages.

## Task Specifications 📝

Your task is to:

1. **Implement `uart_msg_handler.h`**:
   - Define the necessary constants, types, and function prototypes.

2. **Validate the received message**:
   - Inside `uart_recevied_msg_cb()`, ensure that the message starts with the correct magic bytes and includes a valid length.

3. **Callback Implementation**:
   - Set up the callback from `uart_msg_handler.c` to `app.c` for processing and displaying messages.

## Future Enhancements 🌟

- Add message encryption or checksum validation for more secure communication.
- Implement more advanced UART error handling and recovery mechanisms.
- Integrate with additional peripherals or communication interfaces.

## Author ✍️

This project was created by **Abdelrahman Ellithy** on **October 9, 2024**.

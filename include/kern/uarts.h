#ifndef __UARTS_H__
#define __UARTS_H__

#define TERM_RX_NOTIFIER_REQUEST 0
#define TERM_RX_CLIENT_REQUEST 1
#define TERM_TX_NOTIFIER_READY 2
#define TERM_TX_CLIENT_REQUEST 3
#define TERM_WTX_CLIENT_REQUEST 4

#define TRAIN_RX_NOTIFIER_REQUEST 0
#define TRAIN_RX_CLIENT_REQUEST 1
#define TRAIN_TX_NOTIFIER_READY 2
#define TRAIN_TX_CLIENT_REQUEST 3
#define TRAIN_WTX_CLIENT_REQUEST 4

typedef struct UARTMessage {
  int type;
  int tid;
  char data;
  char *wdata;
  struct UARTMessage *next;
} UARTMessage;

void term_rx_server();
void term_tx_server();

void train_rx_server();
void train_tx_server();

#endif


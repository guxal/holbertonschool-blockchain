#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "blockchain.h"

#define TX_OUT_HASH_LEN (sizeof(uint32_t) + EC_PUB_LEN)
/**
 * struct tx_out_s - Transaction output
 *
 * @amount: Amount received
 * @pub:	Receiver's public address
 * @hash:	Hash of @amount and @pub. Serves as output ID
 */
typedef struct tx_out_s
{
	uint32_t	amount;
	uint8_t		pub[EC_PUB_LEN];
	uint8_t		hash[SHA256_DIGEST_LENGTH];
} tx_out_t;

tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN]);


#endif

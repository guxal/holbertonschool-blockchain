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

/**
 * struct unspent_tx_out_s - Unspent transaction output
 *
 * Description: This structure helps identify transaction outputs that were not
 * used in any transaction input yet, making them "available".
 *
 * @block_hash: Hash of the Block containing the transaction @tx_id
 * @tx_id:      ID of the transaction containing @out
 * @out:        Copy of the referenced transaction output
 */
typedef struct unspent_tx_out_s
{
	uint8_t     block_hash[SHA256_DIGEST_LENGTH];
	uint8_t     tx_id[SHA256_DIGEST_LENGTH];
	tx_out_t    out;
} unspent_tx_out_t;

tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN]);

unspent_tx_out_t
*unspent_tx_out_create(uint8_t block_hash[SHA256_DIGEST_LENGTH],
										uint8_t tx_id[SHA256_DIGEST_LENGTH],
										tx_out_t const *out);

#endif

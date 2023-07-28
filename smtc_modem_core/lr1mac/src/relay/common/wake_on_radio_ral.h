/*!
 * \file    wake_on_radio.h
 *
 * \brief   WOR and WOR ACK radio function
 *
 * The Clear BSD License
 * Copyright Semtech Corporation 2023. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted (subject to the limitations in the disclaimer
 * below) provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Semtech corporation nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY
 * THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
 * NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SEMTECH CORPORATION BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _WAKE_ON_RADIO_RADIO_PARAMH_
#define _WAKE_ON_RADIO_RADIO_PARAMH_

#ifdef _cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "smtc_real.h"
#include "radio_planner_types.h"

/**
 * @brief   Fill rp_radio_params_t struct for TX WOR frame
 *
 * @param[in]   real                Regional Abstraction Layer object
 * @param[in]   dr                  Datarate of the WOR
 * @param[in]   freq_hz             Frequency of the WOR
 * @param[in]   preamble_len_symb   Preamble len
 * @param[in]   payload_len         Payload len of the WOR
 * @param[out]  param               Radio parameter structure with WOR infos
 */
void wor_ral_init_tx_wor( smtc_real_t* real, uint8_t dr, uint32_t freq_hz, uint16_t preamble_len_symb,
                          uint8_t payload_len, rp_radio_params_t* param );

/**
 * @brief   Fill rp_radio_params_t struct for RX WOR frame
 *
 * @param[in]   real                Regional Abstraction Layer object
 * @param[in]   dr                  Datarate of the WOR
 * @param[in]   freq_hz             Frequency of the WOR
 * @param[in]   preamble_len_symb   Preamble len
 * @param[in]   payload_len         Payload len of the WOR
 * @param[out]  param               Radio parameter structure with WOR infos
 */
void wor_ral_init_rx_wor( smtc_real_t* real, uint8_t dr, uint32_t freq_hz, wor_cad_periodicity_t cad_period,
                          uint8_t max_payload, rp_radio_params_t* param );

/**
 * @brief Fill rp_radio_params_t struct for periodic CAD
 *
 * @param[in]   lr1_mac     Lr1mac object
 * @param[in]   dr          Datarate of the CAD
 * @param[in]   cad_period  Period between 2 CAD
 * @param[in]   is_first    true for the first single CAD, False for the second 4th symbols
 * @param[in]   wor_toa_ms  TOA of the WOR to be received
 * @param[out]  param       Radio parameter structure with CAD infos
 */
void wor_ral_init_cad( smtc_real_t* lr1_mac, uint8_t dr, wor_cad_periodicity_t cad_period, bool is_first,
                       uint32_t wor_toa_ms, ral_lora_cad_params_t* param );

/**
 * @brief   Fill rp_radio_params_t struct to received LoRaWAN Uplink after a WOR
 *
 * @param[in]   real        Regional Abstraction Layer object
 * @param[in]   max_payload Maximum payload to be received
 * @param[in]   dr          Datarate of the uplink
 * @param[in]   freq_hz     Frequency of the uplink
 * @param[out]  param       Radio parameter structure with LoRaWAN Uplink
 */
void wor_ral_init_rx_msg( smtc_real_t* real, uint8_t max_payload, uint8_t dr, uint32_t freq_hz,
                          rp_radio_params_t* param );

/**
 * @brief Fill rp_radio_params_t struct to send a WOR ACK
 *
 * @param[in]   real        Regional Abstraction Layer object
 * @param[in]   dr          Datarate of the WOR ACK
 * @param[in]   freq_hz     Frequency of the WOR ACK
 * @param[in]   payload_len Len of the WOR ACK
 * @param[out]  param       Radio parameter structure with WOR ACK
 */
void wor_ral_init_tx_ack( smtc_real_t* real, uint8_t dr, uint32_t freq_hz, uint8_t payload_len,
                          rp_radio_params_t* param );

/**
 * @brief Fill rp_radio_params_t struct to receive a WOR ACK
 *
 * @param[in]   real        Regional Abstraction Layer object
 * @param[in]   dr          Datarate of the WOR ACK
 * @param[in]   freq_hz     Frequency of the WOR ACK
 * @param[in]   max_payload Len of the WOR ACK
 * @param[out]  param       Radio parameter structure with WOR ACK
 */
void wor_ral_init_rx_ack( smtc_real_t* real, uint8_t dr, uint32_t freq_hz, uint8_t max_payload,
                          rp_radio_params_t* param );

/**
 * @brief Function called by RP to start the CAD
 *
 * @param rp_void radio planner pointer
 */
void wor_ral_callback_start_cad( void* rp_void );

/**
 * @brief Function called by RP to send WOR and WOR ACK
 *
 * @param rp_void radio planner pointer
 */
void wor_ral_callback_start_tx( void* rp_void );

/**
 * @brief Function called by RP to receive WOR, WOR ACK and LoRaWAN uplink
 *
 * @param rp_void
 */
void wor_ral_callback_start_rx( void* rp_void );

#ifdef _cplusplus
}
#endif
#endif

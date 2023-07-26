/**
 * @file RFID.h
 * @brief RFID (Radio Frequency Identification) header file.
 * @date July 26, 2023
 * @author Ziad Gamalelden
 */

#ifndef APP_RFID_H_
#define APP_RFID_H_

/**
 * @brief Initialize the RFID module.
 *
 * This function initializes the RFID module and sets up the necessary configurations
 * to communicate with the RFID reader.
 *
 * @note This function should be called at the beginning of the application before
 *       any interaction with the RFID module.
 */
void RFID_init(void);

/**
 * @brief Read the RFID tag during entry.
 *
 * This function reads the RFID tag from the RFID reader during entry.
 * It returns the RFID tag as a 16-bit value.
 *
 * @return The RFID tag read during entry.
 */
uint16_t RFID_entry_Read(void);

/**
 * @brief Read the RFID tag during exit.
 *
 * This function reads the RFID tag from the RFID reader during exit.
 * It returns the RFID tag as a 16-bit value.
 *
 * @return The RFID tag read during exit.
 */
uint16_t RFID_exit_Read(void);

#endif /* APP_RFID_H_ */

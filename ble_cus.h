#include <stdint.h>
#include <stdbool.h>
#include "ble.h"
#include "ble_srv_common.h"


//444506f8-5dec-11ea-bc55-0242ac130003

#define CUSTOM_SERVICE_UUID_BASE    { 0x03, 0x00, 0x13, 0xac, 0x42, 0x02, 0x55, 0xbc, 0xea, 0x11, 0xec, 0x5d, 0xf8, 0x06, 0x45, 0x44 }

#define CUSTOM_SERVICE_UUID         0x1400
#define CUSTOM_VALUE_CHAR_UUID      0x1401

// Forward declration of the ble_cus_t type.
typedef struct ble_cus_s ble_cus_t;

/**@brief   Macro for defining a ble_cus instance.
 *
 * @param    _name   Name of the instance.
 *
 */
#define BLE_CUS_DEF(_name)      \
static ble_cus_t _name;                                 \
NRF_SDH_BLE_OBSERVER(_name ## _obs,                     \
                     BLE_HRS_BLE_OBSERVER_PRIO,         \
                     ble_cus_on_ble_evt, &_name);

/**@brief Custom Service init structure.
    This contains all options and data needed for initialization of the service.*/
typedef struct
{
    uint8_t                         initial_custom_value;           /**< Initial custom value */
    ble_srv_cccd_security_mode_t    custom_value_char_attr_md;      /**< Initial security level for Custom characteristics attribute */
} ble_cus_init_t;

/**@brief Custom Service structure. This contains various status information for the service. */
struct ble_cus_s
{
    uint16_t                    service_handle;
    ble_gatts_char_handles_t    custom_value_handles;
    uint16_t                    conn_handle;
    uint8_t                     uuid_type;
};

/**@brief Function for initializing the Custom Service.
 *
 * @param[out]  p_cus       Custom Service structure. This structure will have to be supplied by the application.
 *                          It will be initialized bythis function, and will later be used to identify this particular service instance.
 * @param[in]   p_cus_init  Information needed to initialize the service.
 *
 * @return      NRF_SUCCESS on successful initialization of service, otherwise an error code.
 */
uint32_t ble_cus_init(ble_cus_t * p_cus, const ble_cus_init_t * p_cus_init);

void ble_cus_on_ble_evt( ble_evt_t const * p_ble_evt, void * p_context);
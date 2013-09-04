#include "DeviceHost.h"
#include "NfcService.h"

#define LOG_TAG "nfcd"
#include <cutils/log.h>

DeviceHost::DeviceHost()
{
}

DeviceHost::~DeviceHost()
{
}

void DeviceHost::notifyNdefMessageListeners(void* pTag)
{
  NfcService::nfc_service_send_MSG_NDEF_TAG(pTag);
}

void DeviceHost::notifyTargetDeselected()
{
}

void DeviceHost::notifyTransactionListeners()
{
}

void DeviceHost::notifyLlcpLinkActivation(void* pDevice)
{
  NfcService::nfc_service_send_MSG_LLCP_LINK_ACTIVATION(pDevice);
}

void DeviceHost::notifyLlcpLinkDeactivated(void* pDevice)
{
  NfcService::nfc_service_send_MSG_LLCP_LINK_DEACTIVATION(pDevice);
}

void DeviceHost::notifyLlcpLinkFirstPacketReceived()
{
}

void DeviceHost::notifySeFieldActivated()
{
  NfcService::nfc_service_send_MSG_SE_FIELD_ACTIVATED();
}

void DeviceHost::notifySeFieldDeactivated()
{
  NfcService::nfc_service_send_MSG_SE_FIELD_DEACTIVATED();
}
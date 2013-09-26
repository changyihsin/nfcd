/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_nfcd_NfcService_h
#define mozilla_nfcd_NfcService_h

#include "utils/List.h"
#include "IpcSocketListener.h"
#include "NfcManager.h"

class MessageHandler;
class NfcEvent;

class NfcService : public IpcSocketListener {
public:
  ~NfcService();
  void initialize(NfcManager* pNfcManager, MessageHandler* msgHandler);

  void handleTagDiscovered(NfcEvent* event);
  void handleTagLost(NfcEvent* event);
  void handleLlcpLinkActivation(NfcEvent* event);
  void handleLlcpLinkDeactivation(NfcEvent* event);
  static NfcService* Instance();
  static INfcManager* getNfcManager();

  static void nfc_service_send_MSG_LLCP_LINK_ACTIVATION(void* pDevice);
  static void nfc_service_send_MSG_LLCP_LINK_DEACTIVATION(void* pDevice);
  static void nfc_service_send_MSG_TAG(void* pTag);
  static void nfc_service_send_MSG_SE_FIELD_ACTIVATED();
  static void nfc_service_send_MSG_SE_FIELD_DEACTIVATED();
  static void nfc_service_send_MSG_SE_NOTIFY_TRANSACTION_LISTENERS();

  static bool handleDisconnect();
  int handleConnect(int technology);
  bool handleConfigRequest();
  void handleConfigResponse(NfcEvent* event);
  bool handleReadNdefDetailRequest();
  void handleReadNdefDetailResponse(NfcEvent* event);
  bool handleReadNdefRequest();
  void handleReadNdefResponse(NfcEvent* event);
  bool handleWriteNdefRequest(NdefMessage* ndef);
  void handleWriteNdefResponse(NfcEvent* event);
  void handleCloseRequest();
  void handleCloseResponse(NfcEvent* event);
  bool handlePushNdefRequest(NdefMessage* ndef);
  void handlePushNdefResponse(NfcEvent* event);
  bool handleMakeNdefReadonlyRequest();
  void handleMakeNdefReadonlyResponse(NfcEvent* event);

  void onConnected();

  //TODO put these in public because serviceThread will need to access this.
  android::List<NfcEvent*> mQueue;
  MessageHandler* mMsgHandler;
private:
  static NfcService* sInstance;
  static NfcManager* sNfcManager;
  NfcService();
};

#endif // mozilla_nfcd_NfcService_h

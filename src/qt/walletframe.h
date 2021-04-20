/*
 * Qt4 Bean Cash GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 * Bean Core www.beancash.org 2021
 */
#ifndef WALLETFRAME_H
#define WALLETFRAME_H

#include <QFrame>

class BitbeanGUI;
class ClientModel;
class WalletModel;
class WalletStack;

class WalletFrame : public QFrame
{
    Q_OBJECT
public:
    explicit WalletFrame(BitbeanGUI *_gui);
    ~WalletFrame();

    void setClientModel(ClientModel *clientModel);

    bool addWallet(const QString& name, WalletModel *walletModel);
    bool setCurrentWallet(const QString& name);
    
    void removeAllWallets();

    bool handleURI(const QString &uri);

    void showOutOfSyncWarning(bool fShow);

private:
    BitbeanGUI *gui;
    ClientModel *clientModel;
    WalletStack *walletStack;

public slots:
    /** Switch to overview (home) page */
    void gotoOverviewPage();
    /** Switch to history (transactions) page */
    void gotoHistoryPage();
    /** Switch to address book page */
    void gotoAddressBookPage();
    /** Switch to receive beans page */
    void gotoReceiveBeansPage();
    /** Switch to send beans page */
    void gotoSendBeansPage();

    /** Show Sign/Verify Message dialog and switch to sign message tab */
    void gotoSignMessageTab(QString addr = "");
    /** Show Sign/Verify Message dialog and switch to verify message tab */
    void gotoVerifyMessageTab(QString addr = "");

    /** Encrypt the wallet */
    void encryptWallet(bool status);
    /** Backup the wallet */
    void backupWallet();
    /** Import key pairs */
    void importWallet();
    /** Dump key pairs */
    void dumpWallet();
    /** Change encrypted wallet passphrase */
    void changePassphrase();
    /** Ask for passphrase to unlock wallet temporarily */
    void unlockWallet();
    /** Lock wallet */
    void lockWallet();

    /** Set the encryption status as shown in the UI.
     @param[in] status            current encryption status
     @see WalletModel::EncryptionStatus
     */
    void setEncryptionStatus();
};

#endif // WALLETFRAME_H
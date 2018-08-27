/*
 * Copyright (c) 2015 Meinhard Ritscher <cyc1ingsir@gmail.com>
 * Copyright (c) 2017 Slawomir Pabian <sla.pab.dev@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * For more information on the GPL, please go to:
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "controlpanel.h"
#include "ctrlcharacterspopup.h"
#include "sessionmanager.h"
#include "settings.h"
#include "statusbar.h"
#include "ui_mainwindow.h"
#include "pluginmanager.h"

#include <QFont>
#include <QMainWindow>
#include <QProgressDialog>
#include <QPropertyAnimation>
#include <QtSerialPort/QSerialPort>

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

    enum DeviceState { DEVICE_CLOSED, DEVICE_OPENING, DEVICE_OPEN, DEVICE_CLOSING };

public:
    explicit MainWindow(QWidget *parent = 0, const QString &session = "");
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    void openDevice();
    void closeDevice();
    void processData();
    void handleError(QSerialPort::SerialPortError);
    void printDeviceInfo();
    void showAboutMsg();
    void setHexOutputFormat(bool checked);
    void saveCommandHistory();

private slots:
    /**
     * @brief Action to handle QAction::triggered signal. It removes selected items from inputs history list.
     */
    void removeSelectedInputItems(bool remove);

protected:
    void prevCmd();
    void nextCmd();
    void execCmd();
    void commandFromHistoryClicked(QListWidgetItem *item);
    bool sendString(const QString &s);
    bool sendByte(const char c, unsigned long delay);
    void sendKey();
    void sendFile();
    void readFromStdErr();
    void sendDone(int exitCode, QProcess::ExitStatus exitStatus);
    void closeEvent(QCloseEvent *event);

protected slots:
    /**
     * @brief Handles QCheckBox::stateChanged signal received from RTS checkbox (placed in control panel).
     */
    void setRTSLineState(int checked);

    /**
     * @brief Handles QCheckBox::stateChanged signal received from DTR checkbox (placed in control panel).
     */
    void setDTRLineState(int checked);

private:
    void toggleLogging(bool start);
    void fillLineTerminationChooser(const Settings::LineTerminator setting = Settings::LF);
    void fillProtocolChooser(const Settings::Protocol setting = Settings::PLAIN);
    void killSz();
    void switchSession(const QString &session);
    void updateCommandHistory();

    ControlPanel *controlPanel;
    SessionManager *m_sessionManager;
    PluginManager *m_plugin_manager;
    QSerialPort *m_device;
    DeviceState m_deviceState;
    StatusBar *m_device_statusbar;
    Settings *m_settings;
    QProgressDialog *m_progress;
    int m_progressStepSize;
    QProcess *m_sz;
    bool m_devices_needs_refresh;
    char m_previousChar;
    QTime m_timestamp;
    QFile m_logFile;

    QCompleter *m_commandCompleter;
    QStringListModel *m_command_history_model;
    QMenu *m_command_history_menu;

    /// @brief Popup widget that provides graphical way to enter ASCII control characters into input field.
    popup_widget::CtrlCharactersPopup *m_ctrlCharactersPopup;

    /**
     * @brief m_keyRepeatTimer
     */
    QTimer m_keyRepeatTimer;
    char m_keyCode;

    /**
     * @brief m_cmdBufIndex
     */
    int m_cmdBufIndex;
};

#endif // MAINWINDOW_H

/*
 * Copyright (c) 208 Dimitris Tassopoulos <dimtass@gmail.com>
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

#ifndef MACROPLUGIN_H
#define MACROPLUGIN_H

#include "macrosettings.h"
#include "plugin.h"
#include "settings.h"
#include <QDebug>
#include <QFrame>

namespace Ui
{
class MacroPlugin;
}

class MacroPlugin : public QFrame
{
    Q_OBJECT

public:
    explicit MacroPlugin(QFrame *parent, Settings *settings);
    virtual ~MacroPlugin();
    const Plugin *plugin();
    int processCmd(const QString *text);

signals:
    void sendCmd(QByteArray);
    void unload(Plugin *);

public slots:
    void removePlugin(bool);

private:
    Ui::MacroPlugin *ui;
    Plugin *m_plugin;
    MacroSettings *m_macroSettings;
    Settings *m_settings;
};

#endif // MACROPLUGIN_H

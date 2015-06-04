/*
 * This file is part of the KDE project.
 *
 * Copyright (C) 2007 Trolltech ASA
 * Copyright (C) 2008 Urs Wolfer <uwolfer @ kde.org>
 * Copyright (C) 2008 Laurent Montel <montel@kde.org>
 * Copyright (C) 2008 Michael Howell <mhowell123@gmail.com>
 * Copyright (C) 2009 Dawit Alemayehu <adawit @ kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "kwebengineview.h"
#include "kwebengineview_p.h"
#include "kwebenginepage.h"

#include <QMouseEvent>

KWebEngineView::KWebEngineView(QWidget *parent, bool createCustomPage)
    : QWebEngineView(parent), d(new KWebEngineViewPrivate<KWebEngineView>(this))
{
    if (createCustomPage) {
        setPage(new KWebEnginePage(this));
    }
}

KWebEngineView::~KWebEngineView()
{
    delete d;
}

//bool KWebEngineView::isExternalContentAllowed() const
//{
//    return d->isExternalContentAllowed();
//}

//void KWebEngineView::setAllowExternalContent(bool allow)
//{
//    d->setAllowExternalContent(allow);
//}

//TODO: Work around that QWebEngineView doesn't handle mouse events
void KWebEngineView::wheelEvent(QWheelEvent *event)
{
    if (d->wheelEvent(event->delta())) {
        event->accept();
    } else {
        QWebEngineView::wheelEvent(event);
    }
}

void KWebEngineView::mousePressEvent(QMouseEvent *event)
{
    d->pressedButtons = event->buttons();
    d->keyboardModifiers = event->modifiers();
    QWebEngineView::mousePressEvent(event);
}

void KWebEngineView::mouseReleaseEvent(QMouseEvent *event)
{
//    if (d->mouseReleased(event->pos()) || d->handleUrlPasteFromClipboard(event)) {
//        event->accept();
//        return;
//    }

    QWebEngineView::mouseReleaseEvent(event);
}


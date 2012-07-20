/****************************************************************************
**
** Copyright (C) 2012 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Stephen Kelly <stephen.kelly@kdab.com>
** Contact: http://www.qt-project.org/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include <QtTest/QtTest>
#include <qwidget.h>
#include <qlabel.h>

class tst_QWidgetMetaType : public QObject
{
    Q_OBJECT

public:
    tst_QWidgetMetaType() {}
    virtual ~tst_QWidgetMetaType() {}

private slots:
    void metaObject();
};

class CustomWidget : public QWidget
{
  Q_OBJECT
public:
  CustomWidget(QWidget *parent = 0)
    : QWidget(parent)
  {

  }
};

Q_STATIC_ASSERT(( QMetaTypeId2<QSizePolicy>::IsBuiltIn));
Q_STATIC_ASSERT(( QMetaTypeId2<QWidget*>::IsBuiltIn));
Q_STATIC_ASSERT((!QMetaTypeId2<QList<QSizePolicy> >::IsBuiltIn));
Q_STATIC_ASSERT((!QMetaTypeId2<QMap<QString,QSizePolicy> >::IsBuiltIn));


void tst_QWidgetMetaType::metaObject()
{
    QCOMPARE(QMetaType::metaObjectForType(QMetaType::QWidgetStar), &QWidget::staticMetaObject);
    QCOMPARE(QMetaType::metaObjectForType(qMetaTypeId<QLabel*>()), &QLabel::staticMetaObject);
    QCOMPARE(QMetaType::metaObjectForType(qMetaTypeId<CustomWidget*>()), &CustomWidget::staticMetaObject);
}

QTEST_MAIN(tst_QWidgetMetaType)
#include "tst_qwidgetmetatype.moc"

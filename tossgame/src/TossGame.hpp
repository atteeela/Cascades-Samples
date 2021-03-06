/****************************************************************************
 **
 ** Portions Copyright (C) 2012, 2013  BlackBerry Limited.
 ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 ** All rights reserved.
 ** Contact: BlackBerry Ltd. (http://www.blackberry.com/company/contact/)
 ** Contact: Nokia Corporation (qt-info@nokia.com)
 **
 ** This file is part of the examples of the BB10 Platform and is derived
 ** from a similar file that is part of the Qt Toolkit.
 **
 ** You may use this file under the terms of the BSD license as follows:
 **
 ** "Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **   * Redistributions of source code must retain the above copyright
 **     notice, this list of conditions and the following disclaimer.
 **   * Redistributions in binary form must reproduce the above copyright
 **     notice, this list of conditions and the following disclaimer in
 **     the documentation and/or other materials provided with the
 **     distribution.
 **   * Neither the name of BlackBerry, nor the name of Nokia
 **     Corporation and its Subsidiary(-ies), nor the names of its
 **     contributors may be used to endorse or promote products
 **     derived from this software without specific prior written
 **     permission.
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 **
 ****************************************************************************/

#ifndef TOSSGAME_HPP
#define TOSSGAME_HPP

#include <QtCore/QObject>
#include <QtSensors/QProximitySensor>

QTM_USE_NAMESPACE

/**
 * The TossGame class uses the QProximitySensor class from the QtSensors
 * module to retrieve the current close/non-close status information from the
 * proximity sensor of the device.
 */
//! [0]
class TossGame : public QObject, public QProximityFilter
{
    Q_OBJECT

    // The property to access the current gesture
    Q_PROPERTY(Gesture gesture READ gesture NOTIFY gestureChanged)

    // The property to access the current activity status
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
    // Describes the three possible gestures in the game
    enum Gesture {
        Rock,
        Paper,
        Scissors
    };
    Q_ENUMS(Gesture);

    TossGame(QObject *parent = 0);

Q_SIGNALS:
    // The change notification signals of the properties
    void gestureChanged();
    void activeChanged();

protected:
    /**
     * This method is reimplemented from the QProximityFilter interface and is
     * called by the QProximitySensor whenever new values are available.
     */
    bool filter(QProximityReading *reading);

private:
    // The accessor methods for the properties
    Gesture gesture() const;

    bool active() const;
    void setActive(bool active);

    // The current gesture
    Gesture m_gesture;

    // Whether the sensor is currently active
    bool m_active;

    // Stores the previous close/non-close status of the proximity sensor
    bool m_close;

    // The proximity sensor
    QProximitySensor m_sensor;
};
//! [0]

#endif

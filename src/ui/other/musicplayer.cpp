/*
 * This file is part of EasyRPG Editor.
 *
 * EasyRPG Editor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Editor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Editor. If not, see <http://www.gnu.org/licenses/>.
 */

/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**	 * Redistributions of source code must retain the above copyright
**	   notice, this list of conditions and the following disclaimer.
**	 * Redistributions in binary form must reproduce the above copyright
**	   notice, this list of conditions and the following disclaimer in
**	   the documentation and/or other materials provided with the
**	   distribution.
**	 * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**	   of its contributors may be used to endorse or promote products derived
**	   from this software without specific prior written permission.
**
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
** $QT_END_LICENSE$
**
****************************************************************************/

#include "musicplayer.h"
#include "volumebutton.h"

#include <QtWidgets>
#include <QWidget>
#include <QMediaPlayer>


MusicPlayer::MusicPlayer(QWidget *parent) : QWidget(parent),
	mediaPlayer(nullptr),
	playButton(nullptr),
	volumeButton(nullptr),
	positionSlider(nullptr),
	positionLabel(nullptr),
	infoLabel(nullptr)
{
	createWidgets();
	createShortcuts();

	connect(&mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(updatePosition(qint64)));
	connect(&mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(updateDuration(qint64)));
	connect(&mediaPlayer, SIGNAL(metaDataAvailableChanged(bool)), this, SLOT(updateInfo()));
	connect(&mediaPlayer, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(handleError()));
	connect(&mediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),
			this, SLOT(updateState(QMediaPlayer::State)));
}

void MusicPlayer::openFile()
{
	static QString path = QDir::homePath();
	QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), path, tr("All files (*.*)"));
	if (!filePath.isEmpty()) {
		path = filePath;
		playFile(filePath);
	}
}

void MusicPlayer::playFile(const QString &filePath)
{
	playButton->setEnabled(true);
	infoLabel->setText(QFileInfo(filePath).fileName());

	mediaPlayer.setMedia(QUrl::fromLocalFile(filePath));
	mediaPlayer.play();
}

void MusicPlayer::togglePlayback()
{
	if (mediaPlayer.mediaStatus() == QMediaPlayer::NoMedia)
		openFile();
	else if (mediaPlayer.state() == QMediaPlayer::PlayingState)
		mediaPlayer.pause();
	else
		mediaPlayer.play();
}

void MusicPlayer::seekForward()
{
	positionSlider->triggerAction(QSlider::SliderPageStepAdd);
}

void MusicPlayer::seekBackward()
{
	positionSlider->triggerAction(QSlider::SliderPageStepSub);
}

bool MusicPlayer::event(QEvent *event)
{
	return QWidget::event(event);
}

void MusicPlayer::mousePressEvent(QMouseEvent *event)
{
	offset = event->globalPos() - pos();
	event->accept();
}

void MusicPlayer::mouseMoveEvent(QMouseEvent *event)
{
	move(event->globalPos() - offset);
	event->accept();
}

void MusicPlayer::mouseReleaseEvent(QMouseEvent *event)
{
	offset = QPoint();
	event->accept();
}

void MusicPlayer::updateState(QMediaPlayer::State state)
{
	if (state == QMediaPlayer::PlayingState) {
		playButton->setToolTip(tr("Pause"));
		playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
	} else {
		playButton->setToolTip(tr("Play"));
		playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	}
}

void MusicPlayer::updatePosition(qint64 position)
{
	positionSlider->setValue(static_cast<int>(position));

	QTime duration(0, static_cast<int>(position / 60000), qRound((position % 60000) / 1000.0));
	positionLabel->setText(duration.toString(tr("mm:ss")));
}

void MusicPlayer::updateDuration(qint64 duration)
{
	positionSlider->setRange(0, static_cast<int>(duration));
	positionSlider->setEnabled(duration > 0);
	positionSlider->setPageStep(static_cast<int>(duration / 10));
}

void MusicPlayer::setPosition(int position)
{
	// avoid seeking when the slider value change is triggered from updatePosition()
	if (qAbs(mediaPlayer.position() - position) > 99)
		mediaPlayer.setPosition(position);
}

void MusicPlayer::updateInfo()
{
	QStringList info;
	QString author = mediaPlayer.metaData("Author").toString();
	if (!author.isEmpty())
		info += author;
	QString title = mediaPlayer.metaData("Title").toString();
	if (!title.isEmpty())
		info += title;
	if (!info.isEmpty())
		infoLabel->setText(info.join(tr(" - ")));
}

void MusicPlayer::handleError()
{
	playButton->setEnabled(false);
	infoLabel->setText(tr("Error: %1").arg(mediaPlayer.errorString()));
}

void MusicPlayer::createWidgets()
{
	playButton = new QToolButton(this);
	playButton->setEnabled(false);
	playButton->setToolTip(tr("Play"));
	playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	connect(playButton, SIGNAL(clicked()), this, SLOT(togglePlayback()));

	QAbstractButton *openButton = new QToolButton(this);
	openButton->setText(tr("..."));
	openButton->setToolTip(tr("Open a file..."));
	openButton->setFixedSize(playButton->sizeHint());
	connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));

	volumeButton = new VolumeButton(this);
	volumeButton->setToolTip(tr("Adjust volume"));
	volumeButton->setVolume(mediaPlayer.volume());
	connect(volumeButton, SIGNAL(volumeChanged(int)), &mediaPlayer, SLOT(setVolume(int)));

	positionSlider = new QSlider(Qt::Horizontal, this);
	positionSlider->setEnabled(false);
	positionSlider->setToolTip(tr("Seek"));
	connect(positionSlider, SIGNAL(valueChanged(int)), this, SLOT(setPosition(int)));

	infoLabel = new QLabel(this);
	positionLabel = new QLabel(tr("00:00"), this);
	positionLabel->setMinimumWidth(positionLabel->sizeHint().width());

	QBoxLayout *controlLayout = new QHBoxLayout;
	controlLayout->setMargin(0);
	controlLayout->addWidget(openButton);
	controlLayout->addWidget(playButton);
	controlLayout->addWidget(positionSlider);
	controlLayout->addWidget(positionLabel);
	controlLayout->addWidget(volumeButton);

	QBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(infoLabel);
	mainLayout->addLayout(controlLayout);
}

void MusicPlayer::createShortcuts()
{
	QShortcut *quitShortcut = new QShortcut(QKeySequence::Quit, this);
	connect(quitShortcut, SIGNAL(activated()), qApp, SLOT(quit()));

	QShortcut *openShortcut = new QShortcut(QKeySequence::Open, this);
	connect(openShortcut, SIGNAL(activated()), this, SLOT(openFile()));

	QShortcut *toggleShortcut = new QShortcut(Qt::Key_Space, this);
	connect(toggleShortcut, SIGNAL(activated()), this, SLOT(togglePlayback()));

	QShortcut *forwardShortcut = new QShortcut(Qt::Key_Right, this);
	connect(forwardShortcut, SIGNAL(activated()), this, SLOT(seekForward()));

	QShortcut *backwardShortcut = new QShortcut(Qt::Key_Left, this);
	connect(backwardShortcut, SIGNAL(activated()), this, SLOT(seekBackward()));

	QShortcut *increaseShortcut = new QShortcut(Qt::Key_Up, this);
	connect(increaseShortcut, SIGNAL(activated()), volumeButton, SLOT(increaseVolume()));

	QShortcut *decreaseShortcut = new QShortcut(Qt::Key_Down, this);
	connect(decreaseShortcut, SIGNAL(activated()), volumeButton, SLOT(descreaseVolume()));
}

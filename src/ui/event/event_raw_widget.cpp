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

#include "event_raw_widget.h"
#include "ui_event_raw_widget.h"
#include "common/lcf_widget_binding.h"

EventRawWidget::EventRawWidget(ProjectData& project, QWidget* parent) :
	QWidget(parent),
	m_project(project), ui(new Ui::EventRawWidget)
{
	ui->setupUi(this);

	ui->buttonAddNum->setHidden(true); // FIXME: Not implemented

	LcfWidgetBinding::connect(this, ui->lineString);
	LcfWidgetBinding::connect<int32_t>(this, ui->spinCode);
}

EventRawWidget::~EventRawWidget() {
	delete ui;
}

void EventRawWidget::on_buttonAddNum_clicked() {

}

void EventRawWidget::setData(lcf::rpg::EventCommand* cmd) {
	this->cmd = cmd;

	LcfWidgetBinding::bind(ui->lineString, cmd->string);
	LcfWidgetBinding::bind(ui->spinCode, cmd->code);

	for (size_t i = 0; i < cmd->parameters.size(); ++i) {
		auto& param = cmd->parameters[i];

		auto label = new QLabel(this);
		label->setText(QString("%1:").arg(i+1));
		auto spin = new QSpinBox(this);
		spin->setMinimum(INT_MIN);
		spin->setMaximum(INT_MAX);
		QSizePolicy policy;
		policy.setHorizontalPolicy(QSizePolicy::MinimumExpanding);
		spin->setSizePolicy(policy);
		auto del = new QPushButton(this);
		del->setText("Delete");
		del->setHidden(true); // FIXME: Not implemented

		LcfWidgetBinding::connect<int32_t>(this, spin);
		LcfWidgetBinding::bind(spin, param);

		ui->gridLayoutNum->addWidget(label, i, 0);
		ui->gridLayoutNum->addWidget(spin, i, 1);
		ui->gridLayoutNum->addWidget(del, i, 2);
	}
}

void EventRawWidget::setShowWarning(bool show) {
	ui->labelWarn->setHidden(!show);
}

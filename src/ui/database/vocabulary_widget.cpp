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

#include "vocabulary_widget.h"
#include "ui_vocabulary_widget.h"
#include "common/dbstring.h"
#include "src/common/lcf_widget_binding.h"
#include <lcf/context.h>
#include <iostream>

VocabularyWidget::VocabularyWidget(ProjectData& project, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::VocabularyWidget),
	m_project(project), m_terms(project.database().terms)
{
	ui->setupUi(this);

	lcf::rpg::ForEachString(m_terms, [&](auto& val, const lcf::ContextStructBase<lcf::rpg::Terms>& ctx) {
		auto* line = this->findChild<QLineEdit*>(ToQString(ctx.name));
		if (!line) {
			std::cerr << "BUG: Vocabulary: No widget found for " << ctx.name << "\n";
			return;
		}

		LcfWidgetBinding::connect(this, line);
		LcfWidgetBinding::bind(line, val);
	});
}

VocabularyWidget::~VocabularyWidget()
{
	delete ui;
}

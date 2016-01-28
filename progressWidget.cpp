#include "progressWidget.h"

progressWidget::progressWidget(int progressEnd, int progressBegin, QWidget *parent) : QWidget(parent)
{
	this->progressBegin = progressBegin;
	this->progressEnd = progressEnd;
	this->ratio = abs((float)(progressEnd - progressBegin) / (float)(progressEnd*100));

	this->pbar = new QProgressBar(this);
	pbar->setMaximum(100);

	this->mainLo = new QVBoxLayout;
	this->interruptButton = new QPushButton("interrupt");
	

	mainLo->addWidget(pbar);
	mainLo->addWidget(interruptButton);
	this->setLayout(mainLo);

	connect(interruptButton, SIGNAL(clicked(bool)), SIGNAL(interrupt()));
}


void progressWidget::progressNow(int progress)
{
	pbar->setValue((int)progress*ratio);
}





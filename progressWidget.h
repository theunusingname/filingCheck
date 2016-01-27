#pragma once
#include <QObject>
#include <QWidget>
#include <qprogressbar.h>
#include <qpushbutton.h>
#include <qlayout.h>


class progressWidget : public QWidget
{
    Q_OBJECT
public:
	explicit progressWidget(int progressEnd, int progressBegin=0, QWidget *parent = 0);

private:
	QProgressBar *pbar;
	int percent;
	int progressBegin;
	int progressEnd;
	int currentProgress;
	float ratio;
	QPushButton *interruptButton;
	QVBoxLayout *mainLo;

signals:
	void interrupt();

	public slots :
		void progressNow(int progress);
};


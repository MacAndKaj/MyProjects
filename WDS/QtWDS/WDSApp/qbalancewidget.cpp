#include "qbalancewidget.h"

///QBalanceWidget constructor
/// \brief QBalanceWidget::QBalanceWidget
/// \param parent parent QWidget
///
QBalanceWidget::QBalanceWidget(QWidget *parent) : QWidget(parent){
	this->_Pitch = 0;
	this->_Roll = 0;
}

///QBalanceWidget destructor
/// \brief QBalanceWidget::~QBalanceWidget
///
QBalanceWidget::~QBalanceWidget(){}


///This is overloaded method used when event occurs. This function prints things inside the widget.
/// It uses values of _Roll and _Pitch to rotating a balance thing.
/// \brief QBalanceWidget::paintEvent Overloaded method of QWidget
/// \param event QPaintEvent
///
void QBalanceWidget::paintEvent(QPaintEvent *event){
	int penWidth=8;
	int myRx = this->width()/2-penWidth;
	int myRy = this->height()/2-penWidth;
	int radius = (myRx < myRy ? myRx : myRy);

	float angle_Roll = qDegreesToRadians(static_cast<float>(this->_Roll));
	float angle_Roll90 = qDegreesToRadians(static_cast<float>(this->_Roll+90));
	float angle_Pitch = qDegreesToRadians(static_cast<float>(this->_Pitch));
	float shortDistance = 0.2*radius, longDistance = 0.8*radius;

	QPainter painter;
	QPen pen;
	QPainterPath path;
	QBrush brush;
	QPoint center = event->rect().center();
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);

	pen.setColor(Qt::black);
	brush.setColor(QColor(179, 255, 255,255));
	brush.setStyle(Qt::SolidPattern);

	//---------------------Main circle-------------------------------------
	pen.setWidth(8);
	painter.setPen(pen);
	painter.drawEllipse(center,radius,radius);          //drawing a circle
	path.addEllipse(center,radius,radius);              //creating a field to fill with a color
	painter.fillPath(path,brush);                   //filling
	//---------------------Main circle-------------------------------------

	pen.setColor(QColor(0,0,0,100));
	pen.setWidth(1);
	painter.setPen(pen);
	//----------------------------horizontal lines--------------------------------------
	painter.drawLine(QPoint(center.rx()-radius,center.ry()),
					 QPoint(center.rx()+radius,center.ry()));


	painter.drawLine(QPoint(center.rx()-longDistance,center.ry()-shortDistance),
					 QPoint(center.rx()+longDistance,center.ry()-shortDistance));
	painter.drawLine(QPoint(center.rx()-longDistance,center.ry()+shortDistance),
					 QPoint(center.rx()+longDistance,center.ry()+shortDistance));

	painter.drawLine(QPoint(center.rx()-0.66*longDistance,center.ry()-2*shortDistance),
					 QPoint(center.rx()+0.66*longDistance,center.ry()-2*shortDistance));
	painter.drawLine(QPoint(center.rx()-0.66*longDistance,center.ry()+2*shortDistance),
					 QPoint(center.rx()+0.66*longDistance,center.ry()+2*shortDistance));

	painter.drawLine(QPoint(center.rx()-0.33*longDistance,center.ry()-3*shortDistance),
					 QPoint(center.rx()+0.33*longDistance,center.ry()-3*shortDistance));
	painter.drawLine(QPoint(center.rx()-0.33*longDistance,center.ry()+3*shortDistance),
					 QPoint(center.rx()+0.33*longDistance,center.ry()+3*shortDistance));

	painter.drawLine(QPoint(center.rx()-0.1*longDistance,center.ry()-4*shortDistance),
					 QPoint(center.rx()+0.1*longDistance,center.ry()-4*shortDistance));
	painter.drawLine(QPoint(center.rx()-0.1*longDistance,center.ry()+4*shortDistance),
					 QPoint(center.rx()+0.1*longDistance,center.ry()+4*shortDistance));
	//----------------------------horizontal lines--------------------------------------


	//--------------------------Pitch point-------------------------------------------
	pen.setWidth(radius*0.1);
	pen.setColor(Qt::red);
	painter.setPen(pen);
	painter.drawEllipse(QPoint(center.rx(),center.ry()-longDistance*qSin(angle_Pitch)),static_cast<int>(radius*0.05),static_cast<int>(radius*0.05));
	//--------------------------Pitch point-------------------------------------------


	//------------------------------balance-------------------------------------------
	//          ----/\----
	//      leftl|rl|fl|rightl

	//drawLine - point to point  *---------* drawLine(QPoint1,QPoint2)
	pen.setWidth(6);
	pen.setColor(Qt::black);
	painter.setPen(pen);
	//left line
	painter.drawLine(QPoint(center.rx() - longDistance*qCos(angle_Roll),center.ry() + longDistance*qSin(angle_Roll)),
					 QPoint(center.rx() - shortDistance*qCos(angle_Roll),center.ry() + shortDistance*qSin(angle_Roll)));
	//left rising line
	painter.drawLine(QPoint(center.rx() - shortDistance*qCos(angle_Roll),center.ry() + shortDistance*qSin(angle_Roll)),
					 QPoint(center.rx() + shortDistance*qCos(angle_Roll90),center.ry() - shortDistance*qSin(angle_Roll90)));
	//right falling line
	painter.drawLine(QPoint(center.rx() + shortDistance*qCos(angle_Roll90),center.ry() - shortDistance*qSin(angle_Roll90)),
					 QPoint(center.rx() + shortDistance*qCos(angle_Roll),center.ry() - shortDistance*qSin(angle_Roll)));
	//    //right line
	painter.drawLine(QPoint(center.rx() + shortDistance*qCos(angle_Roll),center.ry() - shortDistance*qSin(angle_Roll)),
					 QPoint(center.rx() + longDistance*qCos(angle_Roll),center.ry() - longDistance*qSin(angle_Roll)));
	//-------------------------------balance------------------------------------

	QWidget::paintEvent(event);
	painter.end();
}


///This is overloaded method resizeEvent from QWidget.
/// \brief QBalanceWidget::resizeEvent
/// \param event forcing resize
///
void QBalanceWidget::resizeEvent(QResizeEvent *event){
	if(this->width() != this->height()){
		this->resize(this->width(),this->height());
		this->update();
	}
	QWidget::resizeEvent(event);
}

///Getter.
/// \brief QBalanceWidget::get_Roll Getter.
/// \return Returns value of Roll angle.
///
int QBalanceWidget::get_Roll()
{
	return this->_Roll;
}


///Getter.
/// \brief QBalanceWidget::get_Pitch Getter.
/// \return Returns value of Pitch angle.
///
int QBalanceWidget::get_Pitch()
{
	return this->_Pitch;
}


///Slot changing a value of Roll angle. Is used when new data appears.
/// \brief QBalanceWidget::ChangeRoll Slot changing Roll angle.
/// \param ang New value of Roll angle.
///
void QBalanceWidget::ChangeRoll(uint16_t& ang){
	if(ang > 360) return;
	else this->_Roll = ang;
	this->update();
	emit RollChanged(this->_Roll);
}

///Slot changing a value of Pitch angle. Is used when new data appears.
/// \brief QBalanceWidget::ChangePitch Slot changing pitch angle.
/// \param ang New value of Pitch angle.
///
void QBalanceWidget::ChangePitch(uint16_t& ang){
	if(ang > 360) return;
	else this->_Pitch = ang;
	this->update();
	emit PitchChanged(this->_Pitch);
}



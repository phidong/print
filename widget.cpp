#include "widget.h"
#include "QtGui"


struct Student {
    QString student_id;
    QString first_name;
    QString middle_name;
    QString last_name;
    float point;
};

struct RoomList {
    QString subject_name;
    QString subject_id;
    QList<Student> students;

};
struct Report{
    QString school_name;
    QString room_name;
    QString rp_id;
    QString rp_day;
    QString rp_title;
    QString term;
    QString year;
    QString subject;
    QString credits;
    QString subject_id;
    QString teacher;
    QString percent;
    QString description;
    QString exam_day;
    QString exam_room;
};
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    RoomList r;
    r.subject_id="101";
    r.subject_name="Co so du lieu";
    for(int i=0;i<100;i++)
    {
        Student s;
        s.student_id="1234";
        s.first_name="Ðong";
        s.middle_name="Phi";
        s.last_name="Nguyen";
        s.point=10;
        r.students.append(s);
    }
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOutputFormat(QPrinter::PdfFormat);    
    QString filename=QFileDialog::getSaveFileName(this,"Save file","/print","PDF(*.pdf)",0,0);
    printer.setOutputFileName(filename);
    QPainter painter(&printer);
    QPolygonF polygon;

    polygon << QPointF(100,0) << QPointF(200,(sqrt(3)*100))<<QPointF(0,(sqrt(3)*100))<<QPointF(100,0);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
//    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    painter.setFont(QFont("Times New Roman",12,1,FALSE));

    //painter.drawPolygon(polygon);
    QPoint p=QPoint(0,0);
//    for(int i=0;i<100;i++)
//    {

//        if(p.y()<printer.pageRect().height())
//        {
//            painter.drawText(QPoint(2000,0),QString::number(printer.pageRect().height()));
//            painter.drawText(p,r.students[i].first_name);
//            QPoint p1=p;
//            p1.setX(p.x()+1500);
//            painter.drawText(p1,QString::number(i));
//            //painter.drawText(p,r.students[i].first_name);
//            p.setX(p.x());
//            p.setY(p.y()+250);
//        }
//        else
//        {
//            printer.newPage();
//            p.setX(0);
//            p.setY(0);
//            painter.drawText(p,r.students[i].first_name);
//            QPoint p1=p;
//            p1.setX(p.x()+1500);
//            painter.drawText(p1,QString::number(i));
//            p.setX(p.x());
//            p.setY(p.y()+250);
//        }
//    }
    //ve mau//
    Report rep;
    rep.school_name="??I H?C S? PH?M TP HCM";
    rep.room_name="PHÒNG ?ÀO T?O";
    rep.rp_id="REP-001";
    rep.rp_day="11/04/2013";
    rep.rp_title="DANH SÁCH GHI ?I?M QUÁ TRÌNH";
    rep.term="2";
    rep.year="2012-2013";
    rep.subject=r.subject_name;
    rep.credits="3";
    rep.subject_id=r.subject_id;
    rep.teacher="Lê ??c Long";
    rep.percent="50%";
    rep.description="Thi vi?t 120 phút";
    rep.exam_day="15/4/2013";
    rep.exam_room="I102";
    //paint
    //header//
    painter.drawText(p.x(),p.y(),rep.school_name);
    painter.drawText(p.x()+500,p.y()+200,rep.room_name);
    painter.drawText(p.x()+7000,p.y(),"M?u in: "+rep.rp_id);
    painter.drawText(p.x()+7000,p.y()+200,"Ngày in: "+rep.rp_day);
    p.setY(800);
    painter.setFont(QFont("Times New Roman",12,QFont::Bold));
    painter.drawText(p.x()+2500,p.y(),rep.rp_title);
    painter.setFont(QFont("Times New Roman",12,1,FALSE));
    p.setY(1000);
    painter.drawText(p.x()+3000,p.y(),"H?c k?:"+rep.term+" - N?m h?c:"+rep.year);
    p.setY(1200);
    painter.drawText(p.x(),p.y(),"Môn h?c: "+rep.subject);
    painter.drawText(p.x()+7000,p.y(),"S? tín ch?: "+rep.credits);
    p.setY(1400);
    painter.drawText(p.x(),p.y(),"Mã môn h?c: "+rep.subject_id);
    painter.drawText(p.x()+7000,p.y(),"Ph?n tr?m quá trình: "+rep.percent);
    p.setY(1600);
    painter.drawText(p.x(),p.y(),"Hình th?c ?ánh giá: "+rep.description);
    painter.drawText(p.x()+4500,p.y(),"Ngày thi: "+rep.exam_day);
    painter.drawText(p.x()+7000,p.y(),"Phòng thi: "+rep.exam_room);
    p.setY(1800);
    QPolygonF hexagon;
    hexagon<<QPointF(4450,p.y())
          <<QPointF(4650,p.y())
         <<QPointF(4750,sqrt(3)*100+p.y())
        <<QPointF(4650,sqrt(3)*200+p.y())
       <<QPointF(4450,sqrt(3)*200+p.y())
      <<QPointF(4350,sqrt(3)*100+p.y())
     <<QPointF(4450,p.y());
    painter.drawPolygon(hexagon);
    //luc giac cach Ngay thi 200
    //luc giac cach table 54 vi` chieu cao hinh luc giac la 346 (sqrt(3)*200)
    p.setY(2200);
    painter.drawRect(p.x(),p.y(),300,300);
    painter.drawText(p.x(),p.y()+200,"STT");

}
Widget::~Widget()
{
}

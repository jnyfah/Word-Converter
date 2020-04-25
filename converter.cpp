#include "converter.h"
#include "ui_converter.h"
#include<QInputDialog>

static QString num;

converter::converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::converter)
{
    ui->setupUi(this);


   //num = num.toDouble();


}

converter::~converter()
{
    delete ui;
}




std::string converter::numtowords(int num, std::string str)
  {

static std::string one[] = {
            "", "one", "two", "three", "four", "five",
                "six","seven", "eight", "nine","ten",
            "eleven", "twelve","thirteen","fourteen","fifteen",
            "sixteen", "seventeen","eighteen","nineteen"
    };

static std::string tens[] = {
            "", "", " twenty ", " thirty ", " fourty ", " fifty ",
                " sixty "," seventy ", " eighty ", " ninty "
    };

std::string word;

 if(num > 19)
     {
         word += tens[num/10] + one [num % 10];
    }else {
          word += one [num];
     }

 if(num)
    {
      word += str;
    }

 return word;
 }



std::string converter::convert(long num)
{
    std::string word;

    word += numtowords(((num / 1000000) % 100), " million ");

   if(num % 100000 < 1000)
   {
      word += numtowords(((num / 100000) % 10), " hundred thousand ");
   }else {
       word += numtowords(((num / 100000) % 10), " hundred,");
   }


  word += numtowords(((num / 1000) % 100), " thousand ");

  word += numtowords(((num / 100) % 10), " hundred ");

   if((num>100) && num % 100)
   {
       word += "and ";
   }

     word += numtowords((num % 100) , "  ");
   return word;
}






void converter::on_pushButton_clicked()
{
      QString value = ui->lineEdit->text();

     std::string s =value.toStdString();

    s.erase(std::remove(s.begin(), s.end(), ','),s.end());   //removing commas

    value = QString::fromStdString(s);

    long num = value.toLong();

    std::string str = convert(num);

    QString qstr = QString::fromStdString(str);

     ui->textEdit->setText(qstr);

}

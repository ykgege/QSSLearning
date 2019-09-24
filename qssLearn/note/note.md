### QSS学习

#### QSS介绍

##### QSS简介

​	QSS称为Qt Style Sheets也就是Qt样式表，它是Qt提供的一种用来自定义控件外观的机制。QSS大量参考了CSS的内容，只不过QSS的功能比CSS要弱很多，体现在选择器要少，可以使用的QSS属性也要少很多，并且并不是所有的属性都可以用在Qt的所有控件上。

##### QSS的语法规则

​    QSS的语法和CSS的语法非常相似，但也有些不同，有些CSS的东西在QSS里被去掉了，QSS也加了些自己特有的东西

##### 样式规则

​    QSS包含了一个样式规则序列，一个样式规则由一个选择器和声明组成，选择器指定哪些部件由规则影响，声明指定哪些属性应该在部件上进行设置。

##### 选择器类型

|   选择器   |           示例            |                             说明                             |
| :--------: | :-----------------------: | :----------------------------------------------------------: |
| 通用选择器 |             *             |                         匹配所有部件                         |
| 类型选择器 |        QPushButton        |                匹配QPushButton及其子类的实例                 |
| 属性选择器 | QPushButton[flat=”false”] | 匹配QPushButton中flat属性为false的实例。可以用此选择器来测试任何支持QVariant::toString()的属性，此外，支持特殊的类属性、类名称。此选择器也可以用来测试动态属性（参考助手：Qt Style Sheets Examples中Customizing Using Dynamic Properties部分）。还可以使用~=替换=，测试QStringList类型的属性是否包含给定的QString。 警告：如果Qt属性值在设置样式之后更改，那么可能需要强制重新计算样式。实现的一个方法是取消样式，然后重新设置一遍。 |
|  类选择器  |       .QPushButton        | 匹配QPushButton的实例，但不包含子类。相当于*[class~=”QPushButton”]。 |
|  ID选择器  |   QPushButton#okButton    |       匹配所有objectName为okButton的QPushButton实例。        |
| 后代选择器 |    QDialog QPushButton    |  匹配属于QDialog后代（孩子，孙子等）的QPushButton所有实例。  |
|  子选择器  |   QDialog > QPushButton   |        匹配属于QDialog直接子类的QPushButton所有实例。        |

##### 子控件

对于样式复杂的部件，需要访问子控件。













#### QSS官网示例

```
//Customizing the Foreground and Background Colors

QLineEdit#lineEdit1{
    color: blue;            //设置Edit中的字体颜色
    background-color: yellow;  //设置Edit中的背景颜色
    selection-color:yellow;  //选中时字体颜色  
    selection-background-color:blue;  //选中时背景颜色
}

//Customizing Using Dynamic Properties
*[mandatoryField="true"]{background-color: yellow}  

    ui->lineEdit1->setProperty("mandatoryField", true);
    ui->lineEdit2->setProperty("mandatoryField", true);
    ui->spinBox->setProperty("mandatoryField", true);
    在许多情况下，我们需要提供具有必填字段的表单。为了向用户指示该字段是必填字段，一种有效的（尽管在美学上是可疑的）解决方案是将黄色用作这些字段的背景色。
    
//Customizing a QPushButton Using the Box Model
QLineEdit#lineEdit1{
    background-color: yellow; //设置Edit中的背景颜色
}
QLineEdit#lineEdit2{
    background-color: blue;  //设置Edit中的背景颜色
}

QPushButton#evilButton {
    background-color: red;  //背景颜色
    border-style: outset;  //边界风格  突出
    border-width: 2px;     //边界宽度
    border-radius: 10px;   //边界圆角
    border-color: beige;   //边界颜色
    font: bold 14px;   //字体  bold 加粗加黑
    min-width: 10em;  该属性值会对元素的宽度设置一个最小限制
    padding: 6px;  //内部填充 
}
```


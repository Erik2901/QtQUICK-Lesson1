import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    width: 640
    height: 200
    visible: true
    title: qsTr("Lesson 1")

    property double a
    property double b
    property double c
    property double p
    property double q
    property double s

    property double x1
    property double x2
    property double x3
    property double y1
    property double y2
    property double y3
    property double s2

    GridLayout{
        rows: 7
        columns: 6
        Label {
            text: "Exercise 2"
            font.pixelSize: 16
            Layout.row: 0
            Layout.column: 0
        }
        Label {
            text: "Triangle a side:"
            font.pixelSize: 14
            Layout.row: 2
            Layout.column: 0
        }
        TextField{
            id:a_side
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
            Layout.row: 2
            Layout.column: 1
        }
        Label {
            text: "Triangle b side:"
            font.pixelSize: 14
            Layout.row: 3
            Layout.column: 0
        }
        TextField{
            id:b_side
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
            Layout.row: 3
            Layout.column: 1
        }
        Label {
            text: "Triangle c side:"
            font.pixelSize: 14
            Layout.row: 4
            Layout.column: 0
        }
        TextField{
            id:c_side
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
        }
        Label {
            text: "Triangle S:"
            font.pixelSize: 14
            Layout.row: 6
            Layout.column: 0
        }
        Label{
            id:tr_s
            Layout.row: 6
            Layout.column: 1
        }
        Button {
            id:calculatebtn
            text: "Calculate"
            onClicked: calculate1()
            Layout.row: 5
            Layout.column: 1
        }
        Label {
            text: "Exercise 3"
            font.pixelSize: 16
            Layout.row: 0
            Layout.column: 3
        }
        Label {
            text: "Triangle A coord:"
            font.pixelSize: 14
            Layout.row: 2
            Layout.column: 3
        }
        TextField{
            id:x1_point
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
            placeholderText: "X1"
            Layout.row: 2
            Layout.column: 4
        }
        TextField{
            id:y1_point
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
            placeholderText: "Y1"
            Layout.row: 2
            Layout.column: 5
        }
        Label {
            text: "Triangle B coord:"
            font.pixelSize: 14
            Layout.row: 3
            Layout.column: 3
        }
        TextField{
            id:x2_point
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
            placeholderText: "X2"
            Layout.row: 3
            Layout.column: 4
        }
        TextField{
            id:y2_point
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
            placeholderText: "Y2"
            Layout.row: 3
            Layout.column: 5
        }
        Label {
            text: "Triangle C coord:"
            font.pixelSize: 14
            Layout.row: 4
            Layout.column: 3
        }
        TextField{
            id:x3_point
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
            placeholderText: "X3"
            Layout.row: 4
            Layout.column: 4
        }
        TextField{
            id:y3_point
            validator: RegularExpressionValidator{
                regularExpression: /^-?[0-9,.]{10}/
            }
            placeholderText: "Y3"
            Layout.row: 4
            Layout.column: 5
        }
        Label {
            text: "Triangle S:"
            font.pixelSize: 14
            Layout.row: 6
            Layout.column: 3
        }
        Label{
            id:tr_s2
            Layout.row: 6
            Layout.column: 4
        }
        Button {
            id:calculatebtn2
            text: "Calculate"
            onClicked: calculate2()
            Layout.row: 5
            Layout.column: 5
        }
        Label{
            Layout.row: 0
            Layout.column: 2
            text: "         "
        }
    }
    function calculate1(){
        if(a_side.text && b_side.text && c_side.text){
            a = a_side.text
            b = b_side.text
            c = c_side.text
            p = (a+b+c) / 2
            q = p*((p-a)*(p-b)*(p-c))
            s = Math.sqrt(q)
            tr_s.text = s
        }
    }

    function calculate2(){
        if(x1_point.text && x2_point.text && x3_point.text &&
                y1_point.text && y2_point.text && y3_point.text){
            x1 = x1_point.text
            x2 = x2_point.text
            x3 = x3_point.text
            y1 = y1_point.text
            y2 = y2_point.text
            y3 = y3_point.text
            s2 = (((x2-x1)*(y3-y1))-((x3-x1)*(y2-y1))) / 2
            if(s2 < 0){
                s2 *= -1;
            }

            tr_s2.text = s2
        }
    }
}

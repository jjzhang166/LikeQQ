function doOperation(op,lineEdit1) {
    var t = (lineEdit1.activeFocus ? lineEdit1.text : lineEdit2.text)

    if (op == leftArrow) {
        t = t.toString().slice(0, -1)
        if (t.length == 0) {
            t = ""
        }
    } else {
        t = t + op.toString()
    }

    lineEdit1.activeFocus ? lineEdit1.text = t : lineEdit2.text = t
}

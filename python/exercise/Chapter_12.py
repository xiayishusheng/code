# -*- coding: cp936 -*-
#第十二章 图形用户界面

import wx

#窗口和组件
'''
##绝对坐标
app = wx.App()
win = wx.Frame(None,title="Simple Editor",size=(410,335))
loadButton = wx.Button(win,label='Open',pos=(225,5),size=(80,25))
saveButton = wx.Button(win,label='Save',pos=(315,5),size=(80,25))
filename = wx.TextCtrl(win,pos=(5,5),size=(210,25))
contents = wx.TextCtrl(win,pos=(5,35),size=(390,260),style=wx.TE_MULTILINE | wx.HSCROLL)
win.Show()
app.MainLoop()
'''
##使用相对坐标
'''
app = wx.App()
win = wx.Frame(None,title="Simple Editor",size=(410,335))
bkg = wx.Panel(win)

loadButton = wx.Button(bkg,label='Open')
saveButton = wx.Button(bkg,label='Save')
filename = wx.TextCtrl(bkg)
contents = wx.TextCtrl(bkg,style=wx.TE_MULTILINE | wx.HSCROLL)

hbox = wx.BoxSizer()
hbox.Add(filename,proportion=1,flag=wx.EXPAND)
hbox.Add(loadButton,proportion=0,flag=wx.LEFT,border=5)
hbox.Add(saveButton,proportion=0,flag=wx.LEFT,border=5)

vbox = wx.BoxSizer(wx.VERTICAL)
vbox.Add(hbox,proportion=0,flag=wx.EXPAND | wx.ALL,border=5)
vbox.Add(contents,proportion=1,flag=wx.EXPAND | wx.LEFT | wx.BOTTOM | wx.RIGHT,border=5)

bkg.SetSizer(vbox)
win.Show()
app.MainLoop()
'''

##事件处理  例子：打开文本和存储文本

def load(event):
    file1 = open(filename.GetValue())
    contents.SetValue(file1.read())
    file1.close()

def save(event):
    file2 = open(filename.GetValue(),'w')
    file2.write(contents.GetValue())
    file2.close()

app = wx.App()
win = wx.Frame(None,title="Simple Editor",size=(410,335))

bkg = wx.Panel(win)

loadButton = wx.Button(bkg,label='Open')
loadButton.Bind(wx.EVT_BUTTON,load)

saveButton = wx.Button(bkg,label='Save')
saveButton.Bind(wx.EVT_BUTTON,save)

filename = wx.TextCtrl(bkg)
contents = wx.TextCtrl(bkg,style=wx.TE_MULTILINE | wx.HSCROLL)

hbox = wx.BoxSizer()
hbox.Add(filename,proportion=1,flag=wx.EXPAND)
hbox.Add(loadButton,proportion=0,flag=wx.LEFT,border=5)
hbox.Add(saveButton,proportion=0,flag=wx.LEFT,border=5)

vbox = wx.BoxSizer(wx.VERTICAL)
vbox.Add(hbox,proportion=0,flag=wx.EXPAND | wx.ALL,border=5)
vbox.Add(contents,proportion=1,flag=wx.EXPAND | wx.LEFT | wx.BOTTOM | wx.RIGHT,border=5)

bkg.SetSizer(vbox)
win.Show()
app.MainLoop()


'''
def hello(event):
    print "Hello World!"

app = wx.App()

win = wx.Frame(None,title="Hello wxPython!",size=(200,100))
button = wx.Button(win,label="Hello")
button.Bind(wx.EVT_BUTTON,hello)
win.Show()
app.MainLoop()
'''


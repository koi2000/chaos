package com.chat01;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

/*
多线程实现多人聊天
1.创建客户端
   1.1要求不能在文字内容区域进行编辑
   1.2输入文字按回车发送在ta里
2.创建服务器端

*/
public class ClientChat extends JFrame {
    private JTextArea ta=new JTextArea(10,20);
    private JTextField tf=new JTextField(20);
    private static final String Connstr="127.0.0.1";
    private static final int ConnPort=8080;
    private Socket s=null;
    private DataOutputStream dos=null;
    private boolean isConn=false;
    private JScrollPane sp=new JScrollPane(ta);

    public ClientChat(){
        super();
    }
    public void init(){
        this.setTitle("User");
        this.add(sp, BorderLayout.CENTER);
        this.add(tf,BorderLayout.SOUTH);
        this.setBounds(300,300,300,400);
        try {
            s=new Socket(Connstr,ConnPort);
            isConn=true;
        } catch (IOException e) {
            e.printStackTrace();
        }
        //对tf做监听，拿到tf的内容
        tf.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String strSend=tf.getText();
                if(strSend.trim().length()==0){
                    return;
                }
                send(strSend);
                //发送的方法

                tf.setText("");
                //ta.setText(strSend);
                //ta.append(strSend+"\n");
            }
        });

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ta.setEditable(false);//不能在文字内容区输入
        tf.requestFocus();//光标聚焦
        try {
            s=new Socket(Connstr,ConnPort);
        } catch (IOException e) {
            e.printStackTrace();
        }
        this.setVisible(true);
        new Thread(new Receive()).start();//启动多线程

    }
    public void send(String str){
        try {
            dos=new DataOutputStream(s.getOutputStream());
            dos.writeUTF(str);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    class Receive implements Runnable{
        @Override
        public void run() {
            while(isConn==true){
                try {
                    DataInputStream dis=new DataInputStream(s.getInputStream());
                    String str = dis.readUTF();
                    ta.append(str);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    public static void main(String[] args) {
        ClientChat cc = new ClientChat();
        cc.init();
    }
}

package com.chat01;
/*
创建服务器端，与客户端连接上
服务器启动，一个客户端可以连接上
在考虑发送信息到客户端上
*/
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Iterator;

public class ServeChat extends JFrame {
    private static final int port=8080;
    private JTextArea serveTa=new JTextArea();
    private JPanel btnTool=new JPanel();
    private JButton startBtn=new JButton("启动");
    private JButton stopBtn=new JButton("停止");
    private ArrayList<ClientConn>cclist=new ArrayList<>();
    private boolean isStart =false;
    private ServerSocket ss=null;
    private JScrollPane sp=new JScrollPane(serveTa);
    //写一个内部类，这个对象是属于服务器端的连接对象
    class ClientConn implements Runnable{
        Socket s1=null;
        public ClientConn(Socket sss){
            this.s1=sss;
            (new Thread(this)).start();
        }
        //同时接受客户端方法

        @Override
        public void run() {
            try {
                DataInputStream dis=new DataInputStream(s1.getInputStream());
                //为了让服务器能够收到客户端的多条信息
                while(isStart){
                    String str=dis.readUTF();
                    System.out.println(s1.getInetAddress()+"|"+s1.getPort()+":"+str+"\n");
                    serveTa.append(s1.getInetAddress()+"|"+s1.getPort()+":"+str+"\n");
                    //遍历cclist，调用send方法,在客户端接受信息是多线程的接
                    Iterator<ClientConn> iterator = cclist.iterator();
                    while(iterator.hasNext()){
                        ClientConn o=iterator.next();
                        o.sendStr(s1.getInetAddress()+"|"+s1.getPort()+":"+str+"\n");
                    }

                }
            }catch(SocketException e){
                System.out.println("一个客户端下线了");
                serveTa.append(s1.getInetAddress()+"|"+s1.getPort()+"下线了");
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
        //每个连接用户发送数据的方法
        public void sendStr(String str){
            try {
                DataOutputStream dosf=new DataOutputStream(this.s1.getOutputStream());
                dosf.writeUTF(str);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    //创建一个服务器

    //private Socket s=null;

    //在创建对象时就会调用一系列的方法
    public ServeChat()  {
        this.setTitle("Manager");
        this.add(sp, BorderLayout.CENTER);
        btnTool.add(startBtn);
        btnTool.add(stopBtn);
        this.add(btnTool,BorderLayout.SOUTH);
        this.setBounds(0,0,500,500);

        if(isStart){
            serveTa.append("服务器已经启动了!\\n");
        }else{
            serveTa.append("服务器还未启动,如需启动请点击启动按钮\\n");
        }
        //this.add(startBtn,BorderLayout.SOUTH);
        //this.add(stopBtn,BorderLayout.SOUTH);

        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                isStart=false;
                try {
                    if(ss!=null){
                        ss.close();
                    }
                    System.out.println("服务器停止！");
                    serveTa.append("服务器断开！\n");
                    System.exit(0);
                } catch (IOException ioException) {
                    ioException.printStackTrace();
                }
            }
        });

        startBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //System.out.println("hhhh");
                try {
                    if(ss==null){
                        ss=new ServerSocket(port);
                    }
                    isStart=true;
                    //System.out.println(isStart);
                    serveTa.append("服务器已经启动了！"+"\n");

                } catch (IOException ioException) {
                    ioException.printStackTrace();
                }
            }

        });
        stopBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                isStart=false;
                try {
                    if(ss!=null){
                        ss.close();
                    }
                    System.exit(0);
                    serveTa.append("服务器断开！\n");
                    System.out.println("服务器停止！");
                } catch (IOException ioException) {
                    ioException.printStackTrace();
                }
            }
        });


        //this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        serveTa.setEditable(false);
        this.setVisible(true);
        startServer();
        //Thread t=new Thread();
    }
    //服务器启动的方法
    public void startServer(){
        //System.out.println("yy");
        try {
            try {
                ss = new ServerSocket(port);
                isStart=true;
            } catch (IOException e) {
                e.printStackTrace();
            }

            //应该可以接受多个客户端的连接
            while(isStart){
                System.out.println("a");
                Socket s=ss.accept();
                cclist.add(new ClientConn(s));
                System.out.println("一个客户端连接服务器："+s.getInetAddress()+"/"+s.getPort()+"\n");
                serveTa.append("一个客户端连接服务器："+s.getInetAddress()+"/"+s.getPort()+"\n");
            }
        }catch (IOException e){
            e.printStackTrace();
        }
        //receiveStr();
    }
    //服务器停止的方法

    //多线程的类，实现类Runnable接口

    //服务器端接受数据的方法应该是多线程的接受
    /*public void receiveStr(){
        try {
            dis=new DataInputStream(s.getInputStream());
            String s = dis.readUTF();
            System.out.println(s);
            serveTa.append(s);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }*/
    public static void main(String[] args) {
        ServeChat sc=new ServeChat();
    }
}

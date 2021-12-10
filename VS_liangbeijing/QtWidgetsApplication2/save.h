#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_save.h"

#include "xiApi.h"
#include <iostream>
#include <deque>
#include <fstream>
//#include <windows.h>
#include <tchar.h> 
#include <thread>


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace cv::ml;
using namespace std;

#include<windows.h>    //ͷ�ļ�  
#include<iostream> 

#include <QFile>
class Save : public QMainWindow
{
	Q_OBJECT

public:
	Save(QWidget *parent = Q_NULLPTR);
	bool WriteData(QString str, const char *data, int length);


	//��װ�ĺ���
	void LoadConfig();
	void ConnectCamera();
	void GetFrame(HANDLE cam);
	/*void SaveData(string str_dir);*/
	int GetNextImage(HANDLE cam);

	std::deque<unsigned char*> m_dequeFrame;//����ԭͼ��ͼ��ָ�룻
											//std::deque<unsigned char*> m_dequeSave;//���洢��ͼ���ͼ��ָ�룻

	bool m_bGrabFlag = false; //�ɼ���־λ
	bool m_bCutFinished = false;//��ͼ�߳̽���
	bool m_rawFlag = false; //�ɼ���־λ

	QString m_QstrExposureTimes;
	QStringList m_QstrExposureTimesList;
	QString m_QstrGains;
	QStringList m_QstrGainsList;
	int temp = 0;


	QString m_QstrSavePath;
	int m_cameraSN;

	int m_saveTime;
	int m_exposureTime;
	int m_gain;
	int m_FPS;
	int pic_width = 2048;
	int pic_height = 2048;

	Mat outImg = Mat::zeros(pic_height, pic_width, CV_8UC1);
	int totalNum = pic_width * pic_height;
	int swich;
	unsigned short * img16 = new unsigned short[totalNum];
	unsigned char * img8 = new unsigned char[totalNum];
	QString qstr_pic;

	string str_savedir;

	//std::mutex mutex_deque;//����deque��
private:
	Ui::SaveClass ui;
};

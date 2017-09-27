// PPPoeAlpha.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>
using namespace Tins;
int main()
{

	NetworkInterface iface = NetworkInterface::default_interface();
	NetworkInterface::Info info = iface.addresses();
	EthernetII eth("77:22:33:11:ad:ad", info.hw_addr);
	eth /= IP("192.168.0.1", info.ip_addr);
	eth /= TCP(13, 15);
	eth /= RawPDU("I'm a payload");
	PacketSender sender;
	sender.send(eth, iface);
    return 0;
}


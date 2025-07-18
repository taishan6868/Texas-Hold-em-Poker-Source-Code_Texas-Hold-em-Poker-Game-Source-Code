
#-----------------------------------------------------------------------

APP           := XGame
TARGET        := AIServer
STRIP_FLAG    := N
TARS2CPP_FLAG :=
CFLAGS        += -lm
CXXFLAGS      += -lm

INCLUDE   += -I/usr/local/cpp_modules/wbl/include
LIB       += -L/usr/local/cpp_modules/wbl/lib -lwbl

INCLUDE   += -I/usr/local/cpp_modules/protobuf/include
LIB       += -L/usr/local/cpp_modules/protobuf/lib -lprotobuf

INCLUDE   += -I/usr/local/mysql/include
LIB       += -L/usr/local/mysql/lib/mysql -lmysqlclient

INCLUDE   += -IGameLogic/22013900
LOCAL_SRC += GameLogic/22013900/NNQSLogic.cpp GameLogic/22013900/NNQSGameData.cpp \
			 GameLogic/22013900/NNQSLogicConfig.cpp

INCLUDE   += -Itimer
LOCAL_SRC += timer/Timer.cpp timer/BatchRobotTimer.cpp

INCLUDE   += -Idb
LOCAL_SRC += db/DBOperator.cpp

INCLUDE   += -IAsyncOperate/RoomSvr
LOCAL_SRC += AsyncOperate/RoomSvr/AsyncPushRobotCallback.cpp AsyncOperate/RoomSvr/AsyncAICalcResultCallback.cpp

INCLUDE   += -IAsyncOperate/HallSvr
LOCAL_SRC += AsyncOperate/HallSvr/AsyncUserInfoCallback.cpp

INCLUDE   += -IMonteCarlo
LOCAL_SRC += MonteCarlo/cards.cpp MonteCarlo/samples.cpp MonteCarlo/simulator.cpp \
 			 MonteCarlo/tables.cpp MonteCarlo/tools.cpp


INCLUDE   += -IThirdParty
LOCAL_SRC += ThirdParty/ThirdPartyManager.cpp ThirdParty/AsyncEpoller.cpp \
			 ThirdParty/AsyncSocket.cpp ThirdParty/ThirdLog.cpp \
			 ThirdParty/NetMsg.cpp ThirdParty/RawBuffer.cpp ThirdParty/TcpClient.cpp

#-----------------------------------------------------------------------
include /home/tarsproto/XGame/Comm/Comm.mk
include /home/tarsproto/XGame/ConfigServer/ConfigServer.mk
include /home/tarsproto/XGame/RoomServer/RoomServer.mk
include /home/tarsproto/XGame/HallServer/HallServer.mk
include /home/tarsproto/XGame/PushServer/PushServer.mk
include /home/tarsproto/XGame/AIServer/AIServer.mk
include /home/tarsproto/XGame/protocols/protocols.mk
include /usr/local/tars/cpp/makefile/makefile.tars

#-----------------------------------------------------------------------

xgame:
	cp -f $(TARGET) /usr/local/app/tars/tarsnode/data/XGame.AIServer/bin/
	cp -f ./config/*conf /usr/local/app/tars/tarsnode/data/XGame.AIServer/bin/


#include "OscOutboundPacketStream.h"
#include "IpEndpointName.h"
#include "OscTypes.h"
#include "UdpSocket.h"


#define ADDRESS "127.0.0.1"
#define PORT 7000

#define OUTPUT_BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    UdpTransmitSocket transmitSocket( IpEndpointName( ADDRESS, PORT ) );
    
    char buffer[OUTPUT_BUFFER_SIZE];
    osc::OutboundPacketStream p( buffer, OUTPUT_BUFFER_SIZE );
    
	p.Clear();

	p<< osc::BeginMessage("/test1")<< "3.14"<< "32.00" <<osc::EndMessage;

    transmitSocket.Send( p.Data(), p.Size() );

	p.Clear();

	return 0;
}
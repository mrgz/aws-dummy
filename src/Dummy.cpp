#include <iostream>
#include <aws/core/Aws.h>
#include <aws/ec2/EC2Client.h>
#include <aws/ec2/model/DescribeInstancesRequest.h>
#include <aws/ec2/model/DescribeInstancesResponse.h>

#include "Dummy.h"

dummy::Dummy::Dummy() {
	Aws::InitAPI( options );
	config.connectTimeoutMs = 30000;
	config.requestTimeoutMs = 30000;
	config.region = Aws::String( Aws::Region::SA_EAST_1 );
}

dummy::Dummy::~Dummy() {
	Aws::ShutdownAPI(options);
}

void dummy::Dummy::exec() {
	Aws::EC2::EC2Client ec2;
	Aws::EC2::Model::DescribeInstancesRequest request;

	while (1) {
		auto outcome = ec2.DescribeInstances(request);
		if (outcome.IsSuccess()) {
			const auto &reservations = outcome.GetResult().GetReservations();
			for (const auto &reservation : reservations) {
				const auto &instances = reservation.GetInstances();
				for (const auto &instance : instances) {
					Aws::String instanceStateString = Aws::EC2::Model::InstanceStateNameMapper::GetNameForInstanceStateName(instance.GetState().GetName());
					std::cout << instanceStateString << std::endl;
				}
			}
		}
		if (outcome.GetResult().GetNextToken().size() > 0) {
			request.SetNextToken(outcome.GetResult().GetNextToken());
		} else {
			break;
		}
	}

}

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import String 
from std_msgs.msg import Float32

class VelocityPublisher(Node):
    def __init__(self):

        self.count = 0

        super().__init__('velocity_publisher')      # 노드 이름
        # 발행자 생성: (메시지타입, 토픽명, 큐깊이)
        # self.pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.pub2 = self.create_publisher(String, '/chatter', 10)
        self.pub3 = self.create_publisher(Float32, '/counter', 10)

        
        # self.timer1 = self.create_timer(0.5, self.tick1)   # 0.5초(200Hz)마다 tick 호출
        self.timer2 = self.create_timer(1, self.tick2)  # 1초마다 tick2 호출
        self.get_logger().info('발행 시작')

    # def tick1(self):
    #     msg = Twist()
    #     msg.linear.x = 12.3      # 0.2 m/s 전진
    #     msg.angular.z = 45.6     # 약간 회전
    #     self.pub.publish(msg)

    def tick2(self):
        self.count += 1

        # msg2 = String()
        # msg2.data = 'Hello ROS2'
        # self.pub2.publish(msg2)

        # msg3 = Float32()
        # msg3.data = 1.0
        # self.pub3.publish(msg3)

        msg2 = String()
        msg2.data = f'Hello ROS2 | Counter: {self.count}'
        self.pub2.publish(msg2)

        msg3 = Float32()
        msg3.data = float(self.count)
        self.pub3.publish(msg3)

def main():
    rclpy.init()
    node = VelocityPublisher()
    rclpy.spin(node)            # 콜백이 돌기 시작
    rclpy.shutdown()

if __name__ == '__main__':
    main()
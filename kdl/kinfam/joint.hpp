#ifndef KDL_JOINT_HPP
#define KDL_JOINT_HPP

namespace KDL {
    
    /**
     * \brief encapsulates a simple joint.
     *
     * This is an <bold>abstract</bold> class.
     * A simple joint is described by the following properties : 
     *      - scale
     *      - offset  
     *      - type
     *      - stiffness and damping
     *
     *  for an easier specification of a kinematic chain.
     * @ingroup KinematicFamily
     */
    class Joint {
    private:
        JointType type;
        double scale;
        double offset;
        double stiffness;
        double damping;
        double inertia;
        
    public:
        typedef enum { RotX,RotY,RotZ,TransX,TransY,TransZ } JointType;
        Joint(JointType type, double scale=1.0, double offset=0.0,double stiffness=0.0,double damping=0.0, double inertia=0.0);
        Joint(const Joint& in);
        Joint& operator = ( const Joint& arg);

        Frame pose(double q);
        Twist twist(double q);
        Twist jac();
        
        virtual ~Joint();
    };
    
} // end of namespace KDL

#endif

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.DirectX.Direct3D;
using Microsoft.DirectX;
using System.Windows.Forms;

namespace TankGraphics
{

    public enum GraphicsReturn
    {
        Success,
        NotInitialized,
        DrawModeNotStarted,
        OtherError
    }


    public class GraphicsManager
    {
        public enum GraphicsResult
        {
            StartupSuccess,
            StartupFail,
            DisposeFail,
            OtherFail
        }


        private float aspectRatio;
        private Device GraphicsDevice;
        private System.IntPtr rendWindow;
        private bool initialized = false;
        //viewpoint
        float cameraPitch;
        float cameraYaw;
        float cameraRoll;
        float cameraXPos;
        float cameraYPos;
        float cameraZPos;


        //we can also use a window handel here if that's easyer to get in C++
        public GraphicsManager(int horisontalRes, int verticalRes, System.IntPtr Window)
        {
            aspectRatio = (float)horisontalRes / (float)verticalRes;
            rendWindow = Window;
            StartupGraphics();
        }

        public int SetViewPoint(float pitch, float yaw, float roll, float Xpos, float Ypos, float Zpos)
        {
            cameraPitch = pitch;
            cameraYaw = yaw;
            cameraRoll = roll;
            cameraXPos = Xpos;
            cameraYPos = Ypos;
            cameraZPos = Zpos;
            return 0;
        }

        public void StartDraw()
        {
            GraphicsDevice.BeginScene();
        }

        public void EndDraw()
        {
            GraphicsDevice.EndScene();
        }

        public int DrawModel(Model ModelToDraw, float pitch, float yaw, float roll, float Xpos, float Ypos, float Zpos)
        {
            if (initialized == false)
            {
                return 1;
            }



            return 0;
        }


        private int StartupGraphics()
        {
            PresentParameters Params = new PresentParameters();
            Params.Windowed = true;
            Params.PresentationInterval = PresentInterval.Immediate;

            Params.EnableAutoDepthStencil = true;
            Params.SwapEffect = SwapEffect.Discard;
            Params.MultiSample = MultiSampleType.None;
            Params.AutoDepthStencilFormat = DepthFormat.D16;

            Params.BackBufferWidth = 1024;
            Params.BackBufferHeight = 768;
            Params.BackBufferFormat = Format.R5G6B5;
            //Params.Windowed = false;



            GraphicsDevice = new Microsoft.DirectX.Direct3D.Device(0, Microsoft.DirectX.Direct3D.DeviceType.Hardware, rendWindow, CreateFlags.HardwareVertexProcessing, Params);



            //if we want to be more modular we can set this later, but for now this goes here
            GraphicsDevice.RenderState.SourceBlend = Blend.SourceAlpha;
            GraphicsDevice.RenderState.DestinationBlend = Blend.InvSourceAlpha;
            GraphicsDevice.RenderState.AlphaBlendEnable = true;

            return (int)GraphicsResult.StartupSuccess;
        }



        //hard coded utility draws
        //draw the ground
        public int DrawGround()
        {
            return 0;
        }

        //draw the skybox
        public int DrawSkybox()
        {
            return 0;
        }


    }

    public class Model
    {
        public Model(Mesh ObjectMesh, Texture ObjectTexture)
        {

        }

        public Model(string XFile)
        {

        }


    }

}

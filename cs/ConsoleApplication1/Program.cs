﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using live2d;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var tw = new System.IO.StreamWriter("TestResult.txt");

            Console.SetOut(tw);
            TestUtil.LDTEST(new LDEulerAnglesTest());
            TestUtil.LDTEST(new LDGridTransformTest());
            TestUtil.LDTEST(new LDIndexLineListTest());
            TestUtil.LDTEST(new LDMathUtilTest());
            TestUtil.LDTEST(new LDMatrix43Test());
            TestUtil.LDTEST(new LDMatrix44Test());
            TestUtil.LDTEST(new LDQuatTest());
            TestUtil.LDTEST(new LDQuadTransformTest());
            TestUtil.LDTEST(new LDSimpleAffineTransformTest());
            TestUtil.LDTEST(new LDTrianglListTest());
            TestUtil.LDTEST(new LDVector3Test());
            TestUtil.LDTEST(new live2d.math.TriangulationTest());
            TestUtil.SCORE();
            tw.Flush();

        }
    }
}

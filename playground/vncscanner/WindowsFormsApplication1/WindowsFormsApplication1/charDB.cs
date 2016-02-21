using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;


namespace WindowsFormsApplication1
{
    
    public class CharBitmapProperty
    {
        private List<int> p;
        
        public CharBitmapProperty() {
            p = new List<int>();
        }

        public CharBitmapProperty( List<int> a )
        {
            p = new List<int>( a );
        }

        public CharBitmapProperty(int[] a)
        {
            p = new List<int>(a);
        }

        public static CharBitmapProperty operator +( CharBitmapProperty c1, CharBitmapProperty c2)
        {
            if (c1.p.Count != c2.p.Count) {
                throw new System.InvalidOperationException("Two CharBitmapProperty objects have different dimension");
            }
            List<int> k = new List<int>();
            for (int i = 0; i < c1.p.Count; i++)
            {
                k.Add( c1.p[i] + c2.p[i]);
            }
            return new CharBitmapProperty(k);
        }

        public static CharBitmapProperty operator -(CharBitmapProperty c1, CharBitmapProperty c2)
        {
            if (c1.p.Count != c2.p.Count)
            {
                throw new System.InvalidOperationException("Two CharBitmapProperty objects have different dimension");
            }
            List<int> k = new List<int>();
            for (int i = 0; i < c1.p.Count; i++)
            {
                k.Add(c1.p[i] - c2.p[i]);
            }
            return new CharBitmapProperty(k);
        }

        public static CharBitmapProperty operator *(CharBitmapProperty c1, CharBitmapProperty c2)
        {
            if (c1.p.Count != c2.p.Count)
            {
                throw new System.InvalidOperationException("Two CharBitmapProperty objects have different dimension");
            }
            List<int> k = new List<int>();
            for (int i = 0; i < c1.p.Count; i++)
            {
                k.Add(c1.p[i] * c2.p[i]);
            }
            return new CharBitmapProperty(k);
        }

        public int magnitude()
        {
            int total = 0;
            for (int i = 0; i < p.Count; i++)
            {
                total += p[i] * p[i];
            }
            return total;
        }

        public string ToString()
        {
            StringWriter strWriter = new StringWriter();
            foreach (var x in this.p)
            {
                strWriter.Write("{0,3} ", x);
            }
            return strWriter.ToString();
        }
    }
}

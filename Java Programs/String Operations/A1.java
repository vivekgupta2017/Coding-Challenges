import java.io.*; 
import java.util.*;
class A1
{

    public static void main(String[] args) throws IOException 
    {  
        String ip="";
        int ch;  
        FileReader fr=null; 
        try
        { 
            fr = new FileReader("input.txt"); 
        } 
        catch (FileNotFoundException fe) 
        { 
            System.out.println("File not found"); 
        } 
   
        while ((ch=fr.read())!=-1)
            ip=ip+((char)ch); 
        //System.out.print(ip);  
        fr.close();
        
        A1 obj=new A1();
        obj.calc(ip);
        char[] r=obj.rev(ip);

        FileWriter fw=new FileWriter("output.txt"); 

        for (int i = 0; i < r.length; i++) 
            fw.write(r[i]);   
        fw.close();
    }

    public void calc(String ip)
    {
        String[] st=ip.split("\\.",0);
        /*for (String a : st) 
            System.out.println(a + "AA");
        */
        float i=0;
        float j=0;
        float k=0;
        String max="";
        HashMap<String, Integer> fr = new HashMap<String, Integer>();
        for(String a : st)
        {
            i++;
            k=k+a.length();
            //System.out.println(k);
            String[] word=a.split("\\r?\\n| ",0);
            
            for (String b : word) 
            {

                if (fr.containsKey(b)) 
                    fr.put(b, fr.get(b) + 1);
                else 
                    fr.put(b, 1);

                //System.out.println(b);
                if(!b.equals(""))
                j++;

                if(b.length() > max.length())
                    max=b;
            }
            //System.out.println("Words in sentence : "+j);
            
        }
        k--;
        float avg_w=j/i;
        float avg_c=k/i;
        //System.out.println("Avg no of words per sentence : " + avg_w);    
        //System.out.println("Avg no of chars per sentence : " + avg_c);

        Set<Map.Entry<String, Integer> > set = fr.entrySet(); 
        String freq = "";
        int val = 0; 
  
        for (Map.Entry<String, Integer> c : set) 
        { 
            if (c.getValue() > val) 
            { 
                val = c.getValue(); 
                freq = c.getKey(); 
            } 
        }
        //System.out.println("Longest word : " + max);
        //System.out.println("Most frequency word : " + freq);
        try
        {
            FileWriter fw=new FileWriter("metrics.txt"); 
     
                fw.write("AVG_NUMBER_WORDS_PER_SENTENCE ="+String.format("%.2f", avg_w)+"\n");
                fw.write("AVG_NUM_CHARS_PER_SENTENCE ="+String.format("%.2f", avg_c)+"\n");
                fw.write("MAX_FREQ_WORD ="+freq+"\n");
                fw.write("LONGEST_WORD ="+max+"\n");   
            fw.close();
        }
        catch(IOException e)
        {
            System.out.println("IO Error");
        }

    }

    public char[] rev(String ip)
    {
        int c=0;
        char tmp;
        char[] ip1 = ip.toCharArray();
        for(int i=0;i<ip.length();i++)
        {
            if(ip1[i]==32||ip1[i]==46||ip1[i]==10||ip1[i]==13)
            {
                int k=c;
                for(int j=i-1; j>=k;j--)
                {
                    tmp=ip1[j];
                    ip1[j]=ip1[k];
                    ip1[k]=tmp;
                    k++;
                }
                c=i+1;
            }
        }

        /*for (int i = 0; i<ip1.length; i++) 
            System.out.print(ip1[i]);
        */
        return ip1;
    }
}
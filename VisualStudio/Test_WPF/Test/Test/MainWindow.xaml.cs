using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Test
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
		public MainWindow()
		{
			InitializeComponent();
			
			//需要显示的字符
			string DTC_str = "hello";
			string DTCState_str = "world";

			//更新数据
			List<User> items = new List<User>();
			items.Add(new User() { DTC = DTC_str + "1", DTCState = DTCState_str + "1" });	//第一行
			items.Add(new User() { DTC = DTC_str + "2", DTCState = DTCState_str + "2" });	//第二行
			lvDTCs.ItemsSource = items;
		}

		private void DTC_SelectionChanged(object sender, SelectionChangedEventArgs e)
		{
			
		}
	}

	public class User
	{
		public string DTC { get; set; }
		public string DTCState { get; set; }
	}
}

use Mojo::Weixin;
my $client = Mojo::Weixin->new(log_encoding=>"utf-8");
$client->load("ShowMsg");
#ֻ�޸�����Ҫ������ͨ��  �޸����������������ͨ��ȫ��ɾ�������巶Χ��ÿ������ͨ����$client��ʼ��});����
#����Ϊ GCM ���ͣ���������ͨ���Թȸ�Ϊ����������vps�Ǻ������ô����ʹ�ã�
$client->load("GCM",data=>{
    api_url => 'https://gcm-http.googleapis.com/gcm/send',
    api_key=>'AIzaSyB18io0hduB_3uHxKD3XaebPCecug27ht8',
    registration_ids=>["�����ѡ��ȸ�����ͨ����ô�뽫�豸���滻�������֣�������˫����"],
    allow_group=>["����Ⱥ��Ϣ�ĺ��룬����Ҫ����ȫ��Ⱥ��Ϣ��ɾ����һ�У�ÿ��Ⱥ����֮��ʹ�� ""ʹ�� , �ָ�Ⱥ��"],
    ban_group=>[],
#����ʵ�⣬�Ѿ����ε�Ⱥ��ϢҲ�����ͣ������뽫���ε�Ⱥ������""��������,�ָ�������е�[]��
});
#����Ϊ MiPush ����
$client->load("MiPush",data=>{
    registration_ids=>["�뽫�豸���滻�������֣�������˫����"],
    allow_group=>[""],
    ban_group=>[],
    allow_discuss=>[],
    ban_discuss=>[],
});
#����Ϊ HwPush ����
$client->load("HwPush",data=>{
    registration_ids=>["�뽫�豸���滻�������֣�������˫����"],
    allow_group=>[""],
    ban_group=>[],
    allow_discuss=>[],
    ban_discuss=>[],
});
#����Ϊ FmPush ����
$client->load("FmPush",data=>{
    registration_ids=>["�뽫�豸���滻�������֣�������˫����"],
    allow_group=>[""],
    ban_group=>[],
    allow_discuss=>[],
    ban_discuss=>[],
    });
$client->load("Openwx",data=>{
    listen => [{host=>"0.0.0.0",port=>6000}, ] ,
});
$client->run(); 

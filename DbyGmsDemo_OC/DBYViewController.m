//
//  DBYViewController.m
//  DbyGmsDemo_OC
//
//  Created by 钟凡 on 2020/8/1.
//  Copyright © 2020 多贝云. All rights reserved.
//

#import "DBYViewController.h"
#import <DbyGms/DbyGmsKit.h>
#import "DBYTableViewCell.h"


@interface DBYViewController () <DbyGmsDelegate, UITableViewDelegate, UITableViewDataSource, DbyGmsChannelDelegate>

@property (nonatomic, strong) DbyGmsKit *dbyGmsKit;
@property (nonatomic, strong) DbyGmsChannel *gmsChannel;

@property (nonatomic, strong) NSMutableArray *channelMessages;
@property (nonatomic, strong) NSMutableArray *peerMessages;
@property (weak, nonatomic) IBOutlet UITableView *channelTableView;
@property (weak, nonatomic) IBOutlet UITableView *peerTableView;
@property (weak, nonatomic) IBOutlet UITextField *uidTextField;
@property (weak, nonatomic) IBOutlet UIButton *connectButton;
@property (weak, nonatomic) IBOutlet UIButton *disconnectButton;
@property (weak, nonatomic) IBOutlet UITextField *channelIdtextField;
@property (weak, nonatomic) IBOutlet UIButton *joinButton;
@property (weak, nonatomic) IBOutlet UIButton *leaveButton;
@property (weak, nonatomic) IBOutlet UITextField *messageTextField;
@property (weak, nonatomic) IBOutlet UITextField *peerIdTextField;
@property (weak, nonatomic) IBOutlet UISegmentedControl *segmented;
@property (weak, nonatomic) IBOutlet UIButton *sendButton;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *inputContainerBottom;

@end


@implementation DBYViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    _channelMessages = [NSMutableArray array];
    _peerMessages = [NSMutableArray array];
    
    _channelTableView.delegate = self;
    _channelTableView.dataSource = self;
    [_channelTableView registerNib:[UINib nibWithNibName:@"DBYTableViewCell" bundle:nil] forCellReuseIdentifier:@"DBYTableViewCell"];

    _peerTableView.delegate = self;
    _peerTableView.dataSource = self;
    [_peerTableView registerNib:[UINib nibWithNibName:@"DBYTableViewCell" bundle:nil] forCellReuseIdentifier:@"DBYTableViewCell"];

    //换成你自己的appid
    _dbyGmsKit = [[DbyGmsKit alloc] initWithAppId:@"123" delegate:self];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyBoardChange:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyBoardChange:) name:UIKeyboardWillHideNotification object:nil];
}
-(void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)onClickConnect:(id)sender
{
    NSString *uid = self.uidTextField.text;
    if (!uid.length) {
        return;
    }
    NSString *token = @"dbyInternalTest"; //换成自己的token
    NSDate *date = [NSDate date];
    int64_t ts = (int64_t)(date.timeIntervalSince1970 * 1000);
    [self.dbyGmsKit loginByToken:token timeStamp:ts userId:uid completion:^(DbyGmsLoginErrorCode errorCode) {
        if (errorCode == DbyGmsLoginErrorOk) {
            self.connectButton.backgroundColor = [UIColor colorWithRed:1 green:0 blue:0 alpha:0.5];
        }
    }];
}
- (IBAction)onClickDisconnect:(id)sender
{
    __weak typeof(self) weakSelf = self;
    [self.dbyGmsKit logoutWithCompletion:^(DbyGmsLogoutErrorCode errorCode) {
        if (errorCode == DbyGmsLogoutErrorOk) {
            weakSelf.connectButton.backgroundColor = UIColor.whiteColor;
            weakSelf.joinButton.backgroundColor = UIColor.whiteColor;
            weakSelf.gmsChannel = nil;
            [weakSelf.peerMessages removeAllObjects];
            [weakSelf.peerTableView reloadData];
        }
    }];
}
- (IBAction)onClickJoin:(id)sender
{
    NSString *channel = self.channelIdtextField.text;
    if (!channel.length) {
        return;
    }
    if (_gmsChannel == nil) {
        _gmsChannel = [self.dbyGmsKit createChannelWithId:channel delegate:self];
    }
    __weak typeof(self) weakSelf = self;
    [_gmsChannel joinWithCompletion:^(DbyGmsJoinChannelErrorCode errorCode) {
        if (errorCode == DbyGmsJoinChannelErrorOk) {
            weakSelf.joinButton.backgroundColor = [UIColor colorWithRed:1 green:0 blue:0 alpha:0.5];
        }
    }];
}
- (IBAction)onClickLeave:(id)sender
{
    __weak typeof(self) weakSelf = self;
    [_gmsChannel leaveWithCompletion:^(DbyGmsLeaveChannelErrorCode errorCode) {
        if (errorCode == DbyGmsLeaveChannelErrorOk) {
            weakSelf.joinButton.backgroundColor = UIColor.whiteColor;
            [weakSelf.channelMessages removeAllObjects];
            [weakSelf.channelTableView reloadData];
        }
    }];
}
- (IBAction)onClickSend:(id)sender
{
    NSString *text = _messageTextField.text;
    
    DbyGmsMessage *message = [[DbyGmsMessage alloc] initWithText:text];
    
    if (_segmented.selectedSegmentIndex == 0) {
        [self sendPeerMessage:message];
    }else {
        [self sendChannelMessage:message];
    }
    
}
- (void)keyBoardChange:(NSNotification *)no {
    if (no.name == UIKeyboardWillShowNotification) {
        CGRect rect = [no.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
        _inputContainerBottom.constant = rect.size.height;
    }
    if (no.name == UIKeyboardWillHideNotification) {
        _inputContainerBottom.constant = 0;
    }
}
- (void)sendPeerMessage:(DbyGmsMessage *)message
{
    NSString *peerId = _peerIdTextField.text;
    DbyGmsSendMessageOptions *options = [[DbyGmsSendMessageOptions alloc] init];
    options.enableOfflineMessaging = true;
    [self.dbyGmsKit sendMessage:message toPeer:peerId sendMessageOptions:options completion:^(DbyGmsSendPeerMessageErrorCode errorCode) {
        
    }];
}
- (void)sendChannelMessage:(DbyGmsMessage *)message
{
    DbyGmsSendMessageOptions *options = [[DbyGmsSendMessageOptions alloc] init];
    options.enableOfflineMessaging = true;
    [_gmsChannel sendMessage:message options:options completion:^(DbyGmsSendChannelMessageErrorCode errorCode) {
        
    }];
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    if (tableView == _channelTableView) {
        return self.channelMessages.count;
    }else {
        return self.peerMessages.count;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    DBYTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DBYTableViewCell"];
    NSDictionary *dict;
    if (tableView == _channelTableView) {
        dict = _channelMessages[indexPath.row];
    }else {
        dict = _peerMessages[indexPath.row];
    }
    cell.nameLabel.text = dict[@"name"];
    cell.valueLabel.text = dict[@"value"];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 44;
}
#pragma mark - DbyGmsKit
- (void)dbyGmsKit:(DbyGmsKit *)kit messageReceived:(DbyGmsMessage *)message fromPeer:(NSString *)peerId {
    NSDictionary *dict = @{
        @"name":peerId,
        @"value":message.text,
    };
    [self.peerMessages insertObject:dict atIndex:0];
    NSIndexPath *index = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.peerTableView insertRowsAtIndexPaths:@[index] withRowAnimation:UITableViewRowAnimationBottom];
}
#pragma mark - DbyGmsChannel
- (void)channel:(DbyGmsChannel *)channel messageReceived:(DbyGmsMessage *)message fromMember:(DbyGmsMember *)member {
    NSDictionary *dict = @{
        @"name":member.userId,
        @"value":message.text,
    };
    [self.channelMessages insertObject:dict atIndex:0];
    NSIndexPath *index = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.channelTableView insertRowsAtIndexPaths:@[index] withRowAnimation:UITableViewRowAnimationBottom];
}
- (void)channel:(DbyGmsChannel *)channel memberJoined:(DbyGmsMember *)member {
    NSDictionary *dict = @{
        @"name":member.userId,
        @"value":@"加入频道",
    };
    [self.channelMessages insertObject:dict atIndex:0];
    NSIndexPath *index = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.channelTableView insertRowsAtIndexPaths:@[index] withRowAnimation:UITableViewRowAnimationBottom];
}
- (void)channel:(DbyGmsChannel *)channel memberLeft:(DbyGmsMember *)member {
    NSDictionary *dict = @{
        @"name":member.userId,
        @"value":@"离开频道",
    };
    [self.channelMessages insertObject:dict atIndex:0];
    NSIndexPath *index = [NSIndexPath indexPathForRow:0 inSection:0];
    [self.channelTableView insertRowsAtIndexPaths:@[index] withRowAnimation:UITableViewRowAnimationBottom];
}

@end

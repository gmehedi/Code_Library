#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000009];
ll trr[1000009];
ll tree[4*100009],lazy[4*100009];
ll sum[1000009];
void build(ll node,ll start,ll end)
{
    if(start==end)
    {
        tree[node]=arr[start];
        return;
    }
     ll mid = (start + end) / 2;

        build(2*node, start, mid);

        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
}
void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}
ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    sum[0]=0;
    for(ll i=1; i<=n; i++)
    {
        cin>>trr[i];
        sum[i]=sum[i-1]+trr[i];
    }
    build(1,1,n);
    vector<int>v;
    for(ll i=1; i<=n; i++)
    {
        ll ans=queryRange(1,1,n,1,i);
        updateRange(1,1,n,1,i,-trr[i]);
        ll res=queryRange(1,1,n,1,i);
        cout<<ans<<" "<<res<<endl;
        v.push_back(abs(ans-(abs(res))));
    }
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
//        if(i==0)cout<<v[i]<<" ";
//        else if(i==n-1)cout<<v[i]-trr[i+1]<<" ";
//        else cout<<v[i]-(sum[n]-sum[i+1])<<" ";
    }
    cout<<endl;
}
